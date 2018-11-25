//
// Created by Jiandan on 2018/10/11.
// Copyright (c) 2018 Jiandan. All rights reserved.
//

import Foundation

/// 用数组实现的队列
struct ArrayQueue<Element>: Queue {
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
    
    var size: Int { return tail - head }
    
    var peek: Element? { return isEmpty ? nil : items[head] }
    
    // 没有数据搬移的实现，即实现了一个有界序列
//    mutating func enqueue(newElement: Element) -> Bool {
//        // 整个队列都占满了
//        if tail == capacity {
//            return false
//        }
//
//        items[tail] = newElement
//        tail += 1
//        return true
//    }
    // 有数据搬移的实现，即实现了一个无界序列
    mutating func enqueue(newElement: Element) -> Bool {
        // 如果 tail == capacity 表示队列末尾没有空间了
        if tail == capacity {
            // 整个队列都占满了
            if head == 0 { return false }
            // 数据搬移
            for i in head ..< tail {
                items[i - head] = items[i]
            }
            // 搬移完之后重新更新 head 和 tail
            tail -= head
            head = 0
        }

        items[tail] = newElement
        tail += 1
        return true
    }
    
    mutating func dequeue() -> Element? {
        if isEmpty {
            return nil
        }
        
        let item = items[head]
        head += 1
        return item
    }
}

/// 使用2个数组实现无界队列，用到 Swift 中 Array 较多的方法
/// 来源：《iOS 面试之道》（故胤道长，唐巧）
struct ArrayQueue2<Element>: Queue {
    /// 输入数组，主要负责入队
    var inArray = [Element]()
    /// 输出数组，主要负责出队
    var outArray = [Element]()
    
    var isEmpty: Bool { return inArray.isEmpty && outArray.isEmpty }
    
    var size: Int { return inArray.count + outArray.count }
    
    // 当 outArray 为空时，返回 inArray 首个元素，否则返回 outArray 末尾元素
    var peek: Element? { return outArray.isEmpty ? inArray.first : outArray.last }
    
    mutating func enqueue(newElement: Element) -> Bool {
        // inArray 添加元素
        inArray.append(newElement)
        return true
    }
    
    mutating func dequeue() -> Element? {
        if outArray.isEmpty {
            // 将 inArray 倒序存入 outArray 中
            outArray = inArray.reversed()
            // 清空 inArray
            inArray.removeAll()
        }
        // 弹出 outArray 最后一个元素
        return outArray.popLast()
    }
}
