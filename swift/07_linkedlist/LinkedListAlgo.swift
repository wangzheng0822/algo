//
// Created by Jiandan on 2018/10/13.
// Copyright (c) 2018 Jiandan. All rights reserved.
//

/**
 * 1) 单链表反转
 * 2) 链表中环的检测
 * 3) 两个有序的链表合并
 * 4) 删除链表倒数第n个结点
 * 5) 求链表的中间结点
 */
import Foundation
/// 单链表反转
func reverseSinglyLinkedList<Element>(head: Node<Element>) -> Node<Element>? {
    var reverseHead: Node<Element>?, currentNode: Node<Element>?, prevNode: Node<Element>?
    currentNode = head
    while currentNode != nil {
        let nextNode = currentNode!.next
        if nextNode == nil {
            reverseHead = currentNode
        }
        currentNode!.next = prevNode
        prevNode = currentNode
        currentNode = nextNode
    }
    return reverseHead
}
/// 检测环
func hasCircle<Element>(head: Node<Element>) -> Bool {
    var fast = head.next
    var slow: Node<Element>? = head
    while fast != nil {
        if fast === slow {
            return true
        }
        fast = fast!.next?.next
        slow = slow!.next
    }
    return false
}
/// 两个有序的链表合并
func mergeSortedLists<Element: Comparable>(headA: Node<Element>?, headB: Node<Element>?) -> Node<Element>? {
    guard let headA = headA else {
        return headB
    }
    guard let headB = headB else {
        return headA
    }
    
    var head: Node<Element>?, tail: Node<Element>?
    var nodeA: Node<Element>? = headA, nodeB: Node<Element>? = headB
    if nodeA!.value! < nodeB!.value! {
        head = nodeA
        nodeA = nodeA!.next
    } else {
        head = nodeB
        nodeB = nodeB!.next
    }
    tail = head
    
    while nodeA != nil, nodeB != nil {
        if nodeA!.value! < nodeB!.value! {
            tail!.next = nodeA
            nodeA = nodeA!.next
        } else {
            tail!.next = nodeB
            nodeB = nodeB!.next
        }
        tail = tail!.next
    }
    
    if nodeA != nil {
        tail?.next = nodeA
    } else {
        tail?.next = nodeB
    }

    return head
}

/// 删除倒数第n个结点
func deleteNode<Element>(at lastNum: Int, in head: Node<Element>) {
    var slow: Node<Element>? = head
    var fast: Node<Element>? = head
    var num = 1
    while fast != nil, num < lastNum {
        fast = fast!.next
        num += 1
    }

    var prevNode: Node<Element>?
    while fast != nil {
        prevNode = slow
        fast = fast!.next
        slow = slow!.next
    }
    prevNode?.next = slow?.next
}

/// 求链表的中间结点
func halfNode<Element>(in head: Node<Element>) -> Node<Element>? {
    var slow: Node<Element>? = head
    var fast: Node<Element>? = head

    while fast?.next != nil, fast?.next?.next != nil {
        fast = fast!.next?.next
        slow = slow!.next
    }
    return slow
}
