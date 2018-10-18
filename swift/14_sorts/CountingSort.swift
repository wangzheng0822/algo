//
//  CountingSort.swift
//  algo
//
//  Created by Wenru Dong on 2018/10/18.
//  Copyright © 2018年 Wenru Dong. All rights reserved.
//

import Foundation

// 假设数组中储存的都是非负整数
public func countingSort(_ a: inout [Int]) {
    if a.count <= 1 { return }
    
    var counts = Array(repeating: 0, count: a.max()! + 1)
    for num in a {
        counts[num] += 1
    }
    for i in 1..<counts.count {
        counts[i] = counts[i-1] + counts[i]
    }
    
    var aSorted = Array(repeating: 0, count: a.count)
    for num in a.reversed() {
        let index = counts[num] - 1
        aSorted[index] = num
        counts[num] -= 1
    }
    
    for (i, num) in aSorted.enumerated() {
        a[i] = num
    }
}
