//
// Created by Jiandan on 2018/10/12.
// Copyright (c) 2018 Jiandan. All rights reserved.
//

import Foundation

protocol Stack {
    /// 持有的数据类型
    associatedtype Element
    /// 是否为空
    var isEmpty: Bool { get }
    /// 队列大小
    var size: Int { get }
    /// 返回队列头部元素
    var peek: Element? { get }
    /// 入栈
    mutating func push(newElement: Element) -> Bool
    /// 出栈
    mutating func pop() -> Element?
}
