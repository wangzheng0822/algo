//
//  QuickSort.swift
//  algo
//
//  Created by Wenru Dong on 2018/10/17.
//  Copyright © 2018年 Wenru Dong. All rights reserved.
//

import Foundation

public func quickSort<T: RandomAccessCollection & MutableCollection>(_ a: inout T) where T.Element: Comparable {
    quickSort(&a, from: a.startIndex, to: a.index(before: a.endIndex))
}

fileprivate func quickSort<T: RandomAccessCollection & MutableCollection>(_ a: inout T, from low: T.Index, to high: T.Index) where T.Element: Comparable {
    if low >= high { return }
    
    let m = partition(&a, from: low, to: high)
    quickSort(&a, from: low, to: a.index(before: m))
    quickSort(&a, from: a.index(after: m), to: high)
}

fileprivate func partition<T: RandomAccessCollection & MutableCollection>(_ a: inout T, from low: T.Index, to high: T.Index) -> T.Index where T.Element: Comparable {
    let pivot = a[low]
    var j = low
    var i = a.index(after: low)
    while i <= high {
        if a[i] < pivot {
            a.formIndex(after: &j)
            a.swapAt(i, j)
        }
        a.formIndex(after: &i)
    }
    a.swapAt(low, j)
    return j
}
