//
// Created by Jiandan on 2018/10/11.
// Copyright (c) 2018 Jiandan. All rights reserved.
//

import Foundation

struct QueueBasedOnLinkedList<Element>: Queue {
    /// 队首
    var head: Node<Element>?
    /// 队尾
    var tail: Node<Element>?
    
    // MARK: Protocol: Queue
    
    var isEmpty: Bool { return head == nil }
    
    var size: Int {
        if isEmpty {
            return 0
        }
        
        var count = 1 // head 本身算一个
        while head?.next != nil {
            count += 1
        }
        
        return count
    }
    
    var peek: Element? { return head?.value }
    
    mutating func enqueue(newElement: Element) -> Bool {
        if isEmpty {
            // 空队列
            let node = Node(value: newElement)
            head = node
            tail = node
        } else {
            tail!.next = Node(value: newElement)
            tail = tail!.next
        }
        return true
    }
    
    mutating func dequeue() -> Element? {
        if isEmpty {
            return nil
        }
        
        let node = head
        head = head!.next
        return node?.value
    }
}
