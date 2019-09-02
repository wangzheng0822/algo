//
// Created by Jiandan on 2018/10/11.
// Copyright (c) 2018 Jiandan. All rights reserved.
//

import Foundation

protocol Queue {
    /// 持有的数据类型
    associatedtype Element
    /// 是否为空
    var isEmpty: Bool { get }
    /// 队列大小
    var size: Int { get }
    /// 返回队列头部元素
    var peek: Element? { get }
    /// 入队
    mutating func enqueue(newElement: Element) -> Bool
    /// 出队
    mutating func dequeue() -> Element?
}
