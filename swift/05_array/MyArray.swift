//
// Created by Jiandan on 2018/10/10.
// Copyright (c) 2018 Jiandan. All rights reserved.
//

import Foundation

// <Element> Swift 泛型，此数组支持不同数据类型
public struct MyArray<Element> {
    private var data: [Element]
    private var capacity = 0 // 数组长度
    private var count = 0 // 已保存的数据个数

    /// 构造方法
    /// - parameter defaultElement: 默认元素，用来占位
    /// - parameter capacity: 数组长度
    init(defaultElement: Element, capacity: Int) {
        data = [Element](repeating: defaultElement, count: capacity)
        self.capacity = capacity
    }
    
    // 根据 index，查找元素
    func find(at index: Int) -> Element? {
        // index 必须在 [0, count)
        guard index >= 0, index < count else {
            return nil
        }
        
        return data[index]
    }
    
    // 根据 index，删除元素
    mutating func delete(at index: Int) -> Bool {
        // index 必须在 [0, count)
        guard index >= 0, index < count else {
            return false
        }
        
        // [index, count - 1) 从 index 开始，元素分别向前移动一位
        for i in index ..< count - 1 {
            data[i] = data[i+1]
        }
        count -= 1
        return true
    }
    
    // 根据 index 插入元素
    mutating func insert(value: Element, at index: Int) -> Bool {
        // index 必须在 [0, count)
        guard index >= 0, index < count, count < capacity else {
            return false
        }
        
        // count - 1 ~ index
        for i in (index ... count - 1).reversed() {
            data[i + 1] = data[i]
        }
        
        data[index] = value
        count += 1
        return true
    }
    
    // 添加元素
    mutating func add(value: Element) -> Bool {
        guard count < capacity else {
            return false
        }
        data[count] = value
        count += 1
        return true
    }
    
    func printAll() {
        print("\(data)")
    }
}
