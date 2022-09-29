import UIKit

public class TreeNode:Equatable
{
    var value:Int?
    var leftSibling:TreeNode?
    var rightSibling:TreeNode?
    
    init(treeValue:Int)
    {
        value = treeValue
    }
}
// Make class TreeNode confirm to Equatable protocol for equal judgement.
extension TreeNode
{
    public static func == (lhs: TreeNode, rhs: TreeNode) -> Bool
    {
        if lhs.value == rhs.value && lhs.rightSibling == rhs.rightSibling && lhs.leftSibling == rhs.leftSibling
        {
            return true
        }
        else
        {
            return false
        }
    }
}

public class BinarySearchTree
{
    // rootNode.
    var treeRootNode:TreeNode?
    public func findNodeInBinarySearchTree(targetValue:Int) -> TreeNode?
    {
        var tempNode = treeRootNode
        while tempNode != nil
        {
            if let tempValue = tempNode?.value
            {
                if tempValue < targetValue
                {
                    tempNode = tempNode?.rightSibling
                }
                else if tempValue > targetValue
                {
                    tempNode = tempNode?.leftSibling
                }
                else
                {
                    print("Successfully find node, value is \(tempValue).")
                    return tempNode
                }
            }
        }
        print("Value not found.")
        return nil
    }
    
    public func insertNodeToBinarySearchTree(targetValue:Int) -> Bool
    {
        if treeRootNode == nil
        {
            treeRootNode = TreeNode(treeValue: targetValue)
            return true
        }
        var tempNode = treeRootNode
        while tempNode != nil
        {
            if let tempValue = tempNode?.value, tempValue < targetValue
            {
                if tempNode?.rightSibling == nil
                {
                    tempNode?.rightSibling = TreeNode(treeValue: targetValue)
                    return true
                }
                tempNode = tempNode?.rightSibling
            }
            if let tempValue = tempNode?.value, tempValue > targetValue
            {
                if tempNode?.leftSibling == nil
                {
                    tempNode?.leftSibling = TreeNode(treeValue: targetValue)
                    return true
                }
                tempNode = tempNode?.leftSibling
            }
            // insert failed because of inserting a same value.
            if let tempValue = tempNode?.value, tempValue == targetValue
            {
                print("The node to be inserted is already existed. Value is \(tempValue). Stopped.")
                return false
            }
        }
        print("Tree is not existed. Stopped.")
        return false
    }
    
    public func deleteNodeInBinarySearchTree(targetValue:Int) -> Bool
    {
        // find node to be deleted.
        var nodeToBeDeleted = treeRootNode
        var fatherNode:TreeNode? = nil
        while let tempNode = nodeToBeDeleted, tempNode.value != targetValue
        {
            fatherNode = tempNode
            if let tempValue = tempNode.value,  tempValue < targetValue
            {
                nodeToBeDeleted = nodeToBeDeleted?.rightSibling
            }
            else if let tempValue = tempNode.value,  tempValue >= targetValue
            {
                nodeToBeDeleted = nodeToBeDeleted?.leftSibling
            }
        }
        // node not found in tree.
        if nodeToBeDeleted == nil
        {
            print("The node to be deleted is not found in tree. Stopped.")
            return false
        }
        let printValue = nodeToBeDeleted?.value
        // case1: Node to be deleted has two siblings.
        if nodeToBeDeleted?.leftSibling != nil && nodeToBeDeleted?.rightSibling != nil
        {
            var minNode = nodeToBeDeleted?.rightSibling
            var fatherNodeOfMinNode = nodeToBeDeleted
            while minNode?.leftSibling != nil
            {
                fatherNodeOfMinNode = minNode
                minNode = minNode?.leftSibling
            }
            nodeToBeDeleted?.value = minNode?.value
            nodeToBeDeleted = minNode
            fatherNode = fatherNodeOfMinNode
        }
        
        // case 2 and 3: Node to be deleted has one sibling or no sibling.
        var siblingNode:TreeNode? = nil
        if let _ = nodeToBeDeleted?.leftSibling
        {
            siblingNode = nodeToBeDeleted?.leftSibling
        }
        if let _ = nodeToBeDeleted?.rightSibling
        {
            siblingNode = nodeToBeDeleted?.rightSibling
        }
        // case: Node to be deleted is rootNode.
        if fatherNode == nil
        {
            treeRootNode = siblingNode
        }
        
        // if case2: set fatherNode's sibling to node's to be deleted sibling according to whether node to be deleted is its fatherNode's leftSibling or rightSibling.
        // if case3: set fatherNode's sibling to nil according to whether node to be deleted is its fatherNode's leftSibling or rightSibling.
        fatherNode?.leftSibling == nodeToBeDeleted ? (fatherNode?.leftSibling = siblingNode) : (fatherNode?.rightSibling = siblingNode)
        print("Successfully deleted node. Value is \(printValue!).")
        return true
    }
    
    // inOrder visit all nodes, print the ordered array.
    public func inOrderPrint(rootNode:TreeNode?)
    {
        guard let tempNode = rootNode else
        {
            return
        }
        inOrderPrint(rootNode: tempNode.leftSibling)
        print("\(tempNode.value!) ", terminator: "")
        inOrderPrint(rootNode: tempNode.rightSibling)
    }
}
// test function.
func mainTest()
{
    let searchTree = BinarySearchTree()
    let array = [3,6,1,2,7,9,21,33,11,34,55,22,10,8]
    //let array = [3,6,1,9]
    // test insert node.
    for index in array
    {
        searchTree.insertNodeToBinarySearchTree(targetValue: index)
    }
    print("All tree nodes are: ", terminator: "")
    searchTree.inOrderPrint(rootNode: searchTree.treeRootNode)
    print("")
    // test find and delete node.
    searchTree.findNodeInBinarySearchTree(targetValue: 21)
    searchTree.deleteNodeInBinarySearchTree(targetValue: 9)
    searchTree.inOrderPrint(rootNode: searchTree.treeRootNode)
    print("")
    searchTree.findNodeInBinarySearchTree(targetValue: 25)
    searchTree.deleteNodeInBinarySearchTree(targetValue: 5)
    // test insert node value that is already existed.
    searchTree.insertNodeToBinarySearchTree(targetValue: 34)
    searchTree.inOrderPrint(rootNode: searchTree.treeRootNode)
}

mainTest()
