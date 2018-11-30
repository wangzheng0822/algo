//
// Created by Jiandan on 2018/10/11.
// Copyright (c) 2018 Jiandan. All rights reserved.
//

import Foundation

/// 循环队列
struct CircularQueue<Element>: Queue {
    /// 数组
    private var items: [Element]
    /// 数组最大长度
    private var capacity = 0
    /// 队头下标
    private var head = 0
    /// 队尾下标
    private var tail = 0

    /// 构造方法
    /// - parameter defaultElement: 默认元素
    /// - parameter capacity: 数组长度
    init(defaultElement: Element, capacity: Int) {
        self.capacity = capacity
        items = [Element](repeating: defaultElement, count: capacity)
    }

    // MARK: Protocol: Queue

    var isEmpty: Bool { return head == tail }

    var size: Int {
        if tail >= head {
            return tail - head
        } else {
            return (tail + 1) + (capacity - head)
        }
    }

    var peek: Element? { return isEmpty ? nil : items[head] }

    mutating func enqueue(newElement: Element) -> Bool {
        // 整个队列都占满了
        if (tail + 1) % capacity == head {
            return false
        }

        items[tail] = newElement
        tail = (tail + 1) % capacity
        return true
    }

    mutating func dequeue() -> Element? {
        if isEmpty {
            return nil
        }

        let item = items[head]
        head = (head + 1) % capacity
        return item
    }
}
