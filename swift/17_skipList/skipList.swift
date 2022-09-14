// Created by AlanLXG on 2022/9/14.

import UIKit
import Foundation
import Darwin

// Config max level of all nodes.
let MAX_LEVEL_OF_SKIP_LIST = 16

// Class declaration of node.
public class SkipListNode
{
    var nodeData:Int
    var nodeLevel:Int
    // Next node of current node in all levels, whose value is first above current node.
    var nodeForwardData:[SkipListNode?]
    public init()
    {
        nodeData = -1
        nodeLevel = 0
        nodeForwardData = Array<SkipListNode?>(repeating: nil, count: MAX_LEVEL_OF_SKIP_LIST)
    }
    // Return a string that containins node value and level.
    open func nodeToString() -> String
    {
        let nodeString = "{ data: \(nodeData); level: \(nodeLevel) }"
        return nodeString
    }
}

// Class declaration of skip list.
public class SkipList
{
    var levelCount:Int
    // Use sentinel node to simplify insert and delete process of a skip list.
    let sentinelNode:SkipListNode
    
    public init()
    {
        levelCount = 1
        sentinelNode = SkipListNode()
    }
    // Find a node with a qualified value.
    
    public func findNode(targetVaule:Int) -> SkipListNode?
    {
        var searchNode = sentinelNode
        for level in (0..<levelCount).reversed()
        {
            while searchNode.nodeForwardData[level] != nil && searchNode.nodeForwardData[level]!.nodeData < targetVaule
            {
                searchNode = searchNode.nodeForwardData[level]!
            }
        }
        if searchNode.nodeForwardData[0] != nil && searchNode.nodeForwardData[0]!.nodeData == targetVaule
        {
            return searchNode.nodeForwardData[0]
        }
        return nil
    }
    // Insert a new node.
    public func insertNewNode(targetValue:Int) -> Void
    {
        let newNode = SkipListNode()
        newNode.nodeData = targetValue
        // generate a random level via random function.
        let randomLevel = genarateRandomLevel()
        newNode.nodeLevel = randomLevel
        // A temp array that contains nodes whose values are just below the current value in all levels.
        var tempForwardNode = Array<SkipListNode?>(repeating: nil, count: randomLevel+1)
        var foundNode = sentinelNode
        // First find the locations to be inserted.
        for level in (0...randomLevel).reversed()
        {
            while foundNode.nodeForwardData[level] != nil && foundNode.nodeForwardData[level]!.nodeData < targetValue
            {
                foundNode = foundNode.nodeForwardData[level]!
            }
            tempForwardNode[level] = foundNode
        }
        for level in 0...randomLevel
        {
            newNode.nodeForwardData[level] = tempForwardNode[level]?.nodeForwardData[level]
            tempForwardNode[level]?.nodeForwardData[level] = newNode
        }
        if levelCount < randomLevel
        {
            levelCount = randomLevel+1
        }
    }
    // Delete node with current value.
    public func deleteNode(targetValue:Int) -> Int
    {
        var signal = -1
        var tempForwardNode = Array<SkipListNode?>(repeating: nil, count: levelCount)
        var tempNode = sentinelNode
        // Need to find the value first.
        for level in (0..<levelCount).reversed()
        {
            while tempNode.nodeForwardData[level] != nil && tempNode.nodeForwardData[level]!.nodeData < targetValue
            {
                tempNode = tempNode.nodeForwardData[level]!
            }
            tempForwardNode[level] = tempNode
        }
        // Delete value.
        if tempNode.nodeForwardData[0] != nil && tempNode.nodeForwardData[0]?.nodeData == targetValue
        {
            for level in (0..<levelCount).reversed()
            {
                if tempForwardNode[level]?.nodeForwardData[level] != nil && tempForwardNode[level]?.nodeForwardData[level]?.nodeData == targetValue
                {
                    tempForwardNode[level]?.nodeForwardData[level] = tempForwardNode[level]?.nodeForwardData[level]?.nodeForwardData[level]
                    signal = 0
                }
            }
        }
        return signal
    }
    // Print all nodes with values and levels of current list.
    public func printCurrentList() -> Void
    {
        var firstNode = sentinelNode.nodeForwardData[0]
        while firstNode != nil
        {
            print(firstNode!.nodeToString())
            firstNode = firstNode?.nodeForwardData[0]
        }
    }
    // Print nodes of qulified level.
    public func printListOfSomeLevel(targetLevel:Int) -> Void
    {
        for level in (0..<MAX_LEVEL_OF_SKIP_LIST)
        {
            var firstNode = sentinelNode
            if targetLevel < 0 || (targetLevel > 0 && targetLevel == level)
            {
                print("第\(level)级数据：")
                while firstNode.nodeForwardData[level] != nil
                {
                    print("\(firstNode.nodeForwardData[level]!.nodeData)")
                    firstNode = firstNode.nodeForwardData[level]!
                }
            }
        }
    }
    // Generate a random number and give it to node's level.
    internal func genarateRandomLevel() -> Int
    {
        var level = 0
        
        for _ in 1..<MAX_LEVEL_OF_SKIP_LIST
        {
            let randomSeed = arc4random()
            // Using random number to be the seed of function "arc4random_uniform()".
            let randomNum = arc4random_uniform(randomSeed)
            if randomNum % 3 == 1
            {
                level += 1
            }
        }
        return level
    }
}
// Test all methods.
func main() -> Void
{
    let skipList = SkipList()
    for value in 1..<50
    {
        if value % 3 == 0
        {
            skipList.insertNewNode(targetValue: value)
        }
    }
    for value in 1..<50
    {
        if value % 3 == 1
        {
            skipList.insertNewNode(targetValue: value)
        }
    }
    skipList.printCurrentList()
    let findNode = skipList.findNode(targetVaule: 27)
    if let tempNode = findNode
    {
        print("find node of value: \(tempNode.nodeData), level is \(tempNode.nodeLevel)")
    }
    else
    {
        print("Node not find.")
    }
    let sig = skipList.deleteNode(targetValue: 27)
    sig == -1 ? print("No such node to delete.") : print("Successfully delete qulified node.")
}

main()
