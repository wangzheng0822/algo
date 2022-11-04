import UIKit

/// Class of the data structure queue which uses array to perform FIFO.
class Queue<QueueType>
{
    var valueArray:[QueueType?] = []
    var frontNode:QueueType?
    {
        if let node = valueArray.first
        {
            return node
        }
        else
        {
            return nil
        }
    }
    /// A property that returns queue's length, using closure and lazy method to initialize it.
    lazy var count:Int = { valueArray.count }()
    /// Add a new value to the queue, with specified value.
    func enQueue(value:QueueType?) -> Void
    {
        valueArray.append(value)
    }
    /// Pop the first value in the queue according to FIFO.
    /// - Returns: The first value in queue.
    func deQueue() -> QueueType?
    {
        guard count > 0 else
        {
            print("No value in queue. Stopped.")
            return nil
        }
        let value = valueArray.first
        valueArray.removeFirst()
        return value!
    }
}

/// Class of ACAutoMachine's node. Because of comparing two node, it needs to confirm to protocol Equatable.
class ACNode:Equatable
{
    /// Method of protocol Equatable, to judge whether two ACNode is equal.
    static func == (lhs: ACNode, rhs: ACNode) -> Bool
    {
        if lhs.nodeData == rhs.nodeData && lhs.isEndingChar == rhs.isEndingChar && lhs.failNode == rhs.failNode && lhs.childrenArray == rhs.childrenArray
        {
            return true
        }
        else
        {
            return false
        }
    }
    var nodeData:Character?
    lazy var childrenArray = [ACNode?](repeating: nil, count: 26)
    var isEndingChar = false
    /// Fail node, or fail pointer, which point to the node of one of the last level in Trie(AC).
    var failNode:ACNode?
    var matchSize:Int = -1
    /// Default init method of ACNode.
    /// - Parameters:
    ///     - nextCharacter: New character to get in Trie.
    init(nextCharacter:Character?)
    {
        nodeData = nextCharacter
    }
    
}
/// The class of a simple implementation of AC auto machine algorithm. AC auto machine is based on Trie, which is a multi-pattern match algorithm. One can use it to judge whether a string contains one or multiple substrings in Trie. AC auto machine is an improvement of Trie.
class ACAutoMachine
{
    let rootNode = ACNode(nextCharacter: nil)
    /// Insert a new string in auto machine. Actually, it is the same method of Trie to insert a new string.
    ///  - Parameters:
    ///     - newString: The string which needs to be insert.
    func insertStringToACAutoMachine(newString:String) -> Void
    {
        var node = rootNode
        for index in newString.indices
        {
            let ascii = Int(newString[index].utf8.first!) - 97
            if node.childrenArray[ascii] == nil
            {
                let newNode = ACNode(nextCharacter: newString[index])
                node.childrenArray[ascii] = newNode
            }
            node = node.childrenArray[ascii]!
        }
        node.isEndingChar = true
    }
    /// The failure pointer builder method, which is the most important one in AC auto machine.
    func buildFailureNode() -> Void
    {
        let nodeQueue:Queue<ACNode> = Queue()
        rootNode.failNode = nil
        nodeQueue.enQueue(value: rootNode)
        while nodeQueue.count != 0
        {
            let currentNode = nodeQueue.deQueue()
            for index in (0..<26)
            {
                let currentNodeChild = currentNode?.childrenArray[index]
                if currentNodeChild == nil { continue }
                if currentNode == rootNode
                {
                    currentNodeChild?.failNode = rootNode
                }
                else
                {
                    var currentFailNode = currentNode?.failNode
                    while currentFailNode != nil
                    {
                        let currentFailNodeChild = currentFailNode?.childrenArray[Int((currentNodeChild?.nodeData?.utf8.first!)!) - 97]
                        if currentFailNodeChild != nil
                        {
                            currentNodeChild?.failNode = currentFailNodeChild
                            break
                        }
                        currentFailNode = currentFailNode?.failNode
                    }
                    if currentFailNode == nil
                    {
                        currentNodeChild?.failNode = rootNode
                    }
                }
                nodeQueue.enQueue(value: currentNodeChild)
            }
        }
    }
    /// Match with a string using AC auto machine.
    func matchWithACAutoMachine(matchString:String) -> Void
    {
        var currentACNode = rootNode
        var matchStringArray = [Character]()
        for i in matchString.indices
        {
            matchStringArray.append(matchString[i])
        }
        for index in (0..<matchString.count)
        {
            let ASCII = Int(matchStringArray[index].utf8.first!) - 97
            while currentACNode.childrenArray[ASCII] == nil && currentACNode != rootNode
            {
                currentACNode = currentACNode.failNode!
            }
            currentACNode = currentACNode.childrenArray[index]!
            if currentACNode == nil
            {
                currentACNode = rootNode
            }
            var tempNode = currentACNode
            while tempNode != rootNode
            {
                // Successfully match string. Print start index and length.
                if tempNode.isEndingChar == true
                {
                    let matchPosition = index - tempNode.matchSize + 1
                    print("Find a match string.")
                    print("From index \(matchPosition), with length \(tempNode.matchSize).")
                }
                tempNode = tempNode.failNode!
            }
        }
    }
}
