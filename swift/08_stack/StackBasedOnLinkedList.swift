//
// Created by Jiandan on 2018/10/12.
// Copyright (c) 2018 Jiandan. All rights reserved.
//

import Foundation

struct StackBasedOnLinkedList<Element>: Stack {
    private var head = Node<Element>() // 哨兵结点，不存储内容
    
    // MARK: Protocol: Stack
    
    var isEmpty: Bool { return head.next == nil }
    
    var size: Int {
        var count = 0
        var cur = head.next
        while cur != nil {
            count += 1
            cur = cur?.next
        }
        return count
    }
    
    var peek: Element? { return head.next?.value }
    
    func push(newElement: Element) -> Bool {
        let node = Node(value: newElement)
        node.next = head.next
        head.next = node
        return true
    }
    
    func pop() -> Element? {
        let node = head.next
        head.next = node?.next
        return node?.value
    }
}
