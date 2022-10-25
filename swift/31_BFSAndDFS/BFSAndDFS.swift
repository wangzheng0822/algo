import UIKit

/// Class of node for linkedList. Its type is NodeType, which must be the same with LinkedList type and both confirm to protocol BinaryInteger. This means all the classes and methods below only take Int-Like type into processes.
class Node<NodeType: BinaryInteger>
{
    var nodeValue:NodeType?
    var nextNode:Node<NodeType>?
}

/// Class of LinkedList with some uncomplete oprations, including add a node to the tail of list.
class LinkedList<ItemType: BinaryInteger>
{
    var sentinalNode:Node<ItemType>?
    var sumOfNode:Int = 0
    /// Default init method of LinkedList.
    /// - Parameters:
    /// - Returns: An instance of LinkedList.
    init()
    {
        let node = Node<ItemType>()
        sentinalNode = node
        sentinalNode?.nodeValue = -1
        sentinalNode?.nextNode = nil
    }
    /// Add a new node to the tail of a LinkedList.
    /// - Parameters:
    ///     - value: the new node value to be inserted.
    func addNodeToTail(value: ItemType) -> Void
    {
        let newNode = Node<ItemType>()
        if sentinalNode?.nextNode == nil
        {
            newNode.nodeValue = value
            sentinalNode?.nextNode = newNode
            sumOfNode += 1
        }
        else
        {
            var previousNode = sentinalNode?.nextNode
            while previousNode?.nextNode != nil
            {
                previousNode = previousNode?.nextNode
            }
            newNode.nodeValue = value
            previousNode?.nextNode = newNode
            sumOfNode += 1
        }
    }
    /// Return the node value with the specific subcript.
    /// - Parameters:
    ///     - withSubScript: specify the subscript of list. For instance, withSubscript = 2 means return the 3rd value in the list.
    /// - Returns: Value of the specific node.
    func getNode(withSubscript:Int) -> ItemType?
    {
        var count = 0
        var nextNode = sentinalNode?.nextNode
        while count != withSubscript
        {
            count += 1
            nextNode = nextNode?.nextNode
        }
        return nextNode?.nodeValue
    }
    
    /// Print all node values in the list.
    func printNodeValue() -> Void
    {
        while let tempNode = sentinalNode?.nextNode
        {
            print("\(tempNode.nodeValue!) ", terminator: "")
        }
    }
}
/// Class of a queue. Used only in BFS algorithm.
class Queue<QueueType:BinaryInteger>
{
    var valueArray:[QueueType] = []
    var front:QueueType?
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
    var count:Int { valueArray.count }
    
    /// Add a new value to the queue, with specified value.
    func enQueue(value:QueueType) -> Void
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
/// Class declaration of undirected graphs.
class Graph<VertexType:BinaryInteger>
{
    var vertexCount:Int = 0
    var adjcentTable:[LinkedList<VertexType>] = []
    var previous:[VertexType] = []
    var isFoundInDFS:Bool = false
    /// Default init method of graph.
    /// - Parameters:
    ///     - numOfVertex: The total number of vertexes in a graph you wish to get.
    init(numOfVertex:Int)
    {
        vertexCount = numOfVertex
        for _ in (0..<vertexCount)
        {
            adjcentTable.append(LinkedList<VertexType>())
        }
    }
    
    /// Build a graph using two vertexes, add two edges for each one of them. If you want build a graph with some vertexes, first you need to invoke this instant method.
    /// - Parameters:
    ///     - vertex: The source vertex of two edges.
    ///     - anVertex: The destination vertex of two edges.
    func addEdge(src vertex:Int, dst anVertex:Int) -> Void
    {
        adjcentTable[vertex].addNodeToTail(value: VertexType(anVertex))
        adjcentTable[anVertex].addNodeToTail(value: VertexType(vertex))
    }
    
    /// Breadth-First-Search method in undirected graph. Use it to find a shortest path from `startVertex` to `endVertex`.
    /// - Parameters:
    ///     - startVertex: The start point of a path in a graph.
    ///     - endVertex: The end point of a path in a graph.
    func BFS(startVertex:Int, endVertex:Int) -> Void
    {
        if startVertex == endVertex
        {
            print("Start is the end.")
            return
        }
        var visited = Array<Bool>(repeating: false, count: vertexCount)
        visited[startVertex] = true
        let queue:Queue<VertexType> = Queue()
        queue.enQueue(value: VertexType(startVertex))
        for _ in (0..<vertexCount)
        {
            previous.append(-1)
        }
        while queue.count != 0
        {
            let currentVer = queue.deQueue()
            for index in 0..<adjcentTable[currentVer as! Int].sumOfNode
            {
                let vertexInTable = adjcentTable[currentVer as! Int].getNode(withSubscript: index)
                if visited[vertexInTable as! Int] == false
                {
                    previous[Int(vertexInTable!)] = currentVer!
                    if vertexInTable! == endVertex
                    {
                        print("Successfully found destination using BFS. The shortest path is: ")
                        printValue(startVertex: startVertex, endVertex: endVertex)
                        print("\n")
                        return
                    }
                    visited[Int(vertexInTable!)] = true
                    queue.enQueue(value: vertexInTable!)
                }
            }
        }
    }
    /// Depth-First-Search method in undirected graph. Use it to find a path from `startVertex` to `endVertex`. Noticed that it may not be the shortest path.
    /// - Parameters:
    ///     - startVertex: The start point of a path in a graph.
    ///     - endVertex: The end point of a path in a graph.
    func DFS(startVertex:Int, endVertex:Int) -> Void
    {
        if startVertex == endVertex
        {
            print("Start is the end.")
            return
        }
        var visited = Array<Bool>(repeating: false, count: vertexCount)
        for _ in (0..<vertexCount)
        {
            previous.append(-1)
        }
        recursionOfDFS(start: startVertex, end: endVertex, visitedArray: &visited)
        printValue(startVertex: startVertex, endVertex: endVertex)
    }
    
    /// Recursion method in DFS. DFS uses it to search path.
    /// - Parameters:
    ///     - start: The start point of a path in a sub-graph.
    ///     - end: The end point of a path in a sub-graph.
    ///     - visitedArray: An array that records whether the vertex has been visited.
    func recursionOfDFS(start:Int, end:Int, visitedArray:inout [Bool]) -> Void
    {
        if isFoundInDFS == true
        {
            return
        }
        visitedArray[start] = true
        if start == end
        {
            isFoundInDFS = true
            print("Successfully found destination using DFS. The path is: ")
            return
        }
        for index in (0..<adjcentTable[start].sumOfNode)
        {
            let currentVer = adjcentTable[start].getNode(withSubscript: index)
            if visitedArray[currentVer as! Int] == false
            {
                previous[currentVer as! Int] = VertexType(start)
                recursionOfDFS(start: currentVer as! Int, end: end, visitedArray: &visitedArray)
            }
        }
    }
    
    /// Print the vertex value in the path.
    ///  - Parameters:
    ///     - startVertex: The start point of a path in a graph.
    ///     - endVertex: The end point of a path in a graph.
    func printValue(startVertex:Int, endVertex:Int) -> Void
    {
        if previous[endVertex] != -1 && startVertex != endVertex
        {
            printValue(startVertex: startVertex, endVertex: Int(previous[endVertex]))
        }
        print("\(endVertex) ",terminator: "")
    }
}

/// Test function of building a graph, search paths using BFS and DFS.
func mainTest() -> Void
{
    // Graph.addEdge -> LinkedList.addNodeToTail
    let graph = Graph<Int>(numOfVertex: 8)
    graph.addEdge(src: 0, dst: 3)
    graph.addEdge(src: 0, dst: 1)
    graph.addEdge(src: 1, dst: 2)
    graph.addEdge(src: 1, dst: 4)
    graph.addEdge(src: 2, dst: 5)
    graph.addEdge(src: 3, dst: 4)
    graph.addEdge(src: 4, dst: 5)
    graph.addEdge(src: 4, dst: 6)
    graph.addEdge(src: 5, dst: 7)
    graph.addEdge(src: 6, dst: 7)
    
    graph.BFS(startVertex: 0, endVertex: 7)
    graph.DFS(startVertex: 0, endVertex: 7)
}

// Tested only with integer, from 0 to another number with continuity.
mainTest()
