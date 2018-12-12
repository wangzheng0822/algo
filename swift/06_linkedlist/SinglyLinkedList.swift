//
//  Created by Jiandan on 2018/10/12.
//  Copyright © 2018 Jiandan. All rights reserved.
//

import Foundation

class Node<T> {
    var value: T?
    var next: Node?
    
    init(){}
    
    init(value: T) {
        self.value = value
    }
}

/// 单链表
/// 实现插入、删除、查找操作
class List<Element: Equatable> {
    private var dummy = Node<Element>() // 哨兵结点，不存储数据
    var size: Int {
        var num = 0
        var tmpNode = dummy.next
        while tmpNode != nil {
            num += 1
            tmpNode = tmpNode!.next
        }
        return num
    }
    var isEmpty: Bool { return size > 0 }
    
    /// find node with value
    func node(with value: Element) -> Node<Element>? {
        var node = dummy.next
        while node != nil {
            if node!.value == value {
                return node
            }
            node = node!.next
        }
        
        return nil
    }
    // 约定：链表的 index 从 1 开始
    func node(at index: Int) -> Node<Element>? {
        var num = 1
        var node = dummy.next
        while node != nil {
            if num == index {
                return node
            }
            node = node!.next
            num += 1
        }
        return nil
    }
    
    func insertToHead(value: Element) {
        let newNode = Node(value: value)
        return insertToHead(node: newNode)
    }
    
    func insertToHead(node: Node<Element>) {
        node.next = dummy.next
        dummy.next = node
    }
    
    func insert(after node: Node<Element>, newValue: Element) {
        let newNode = Node(value: newValue)
        return insert(after: node, newNode: newNode)
    }

    func insert(after node: Node<Element>, newNode: Node<Element>) {
        newNode.next = node.next
        node.next = newNode
    }
    
    func insert(before node: Node<Element>, newValue: Element) {
        let newNode = Node(value: newValue)
        return insert(before: node, newNode: newNode)
    }
    
    func insert(before node: Node<Element>, newNode: Node<Element>) {
        var lastNode = dummy
        var tmpNode = dummy.next

        while tmpNode != nil {
            if tmpNode === node {
                newNode.next = tmpNode
                lastNode.next = newNode
                break
            }
            lastNode = tmpNode!
            tmpNode = tmpNode!.next
        }
    }
    
    func delete(node: Node<Element>) {
        var lastNode = dummy
        var tmpNode = dummy.next

        while tmpNode != nil {
            if tmpNode === node {
                lastNode.next = tmpNode!.next
                break
            }

            lastNode = tmpNode!
            tmpNode = tmpNode!.next
        }
    }
    /// 删除首个 value 符合要求的结点
    func delete(value: Element) {
        var lastNode = dummy
        var tmpNode = dummy.next
        while tmpNode != nil {
            if tmpNode!.value == value {
                lastNode.next = tmpNode!.next
                break
            }

            lastNode = tmpNode!
            tmpNode = tmpNode!.next
        }
    }
}
