//
//  sorts.swift
//  algo
//
//  Created by Wenru Dong on 2018/10/14.
//  Copyright © 2018年 Wenru Dong. All rights reserved.
//

import Foundation

public func mergeSort<T>(_ a: inout T) where T: RandomAccessCollection, T: MutableCollection, T.Element: Comparable {
    mergeSort(&a, from: a.startIndex, to: a.index(before: a.endIndex))
}

fileprivate func mergeSort<T>(_ a: inout T, from low: T.Index, to high: T.Index) where T: RandomAccessCollection, T: MutableCollection, T.Element: Comparable {
    if low >= high { return }
    let dist = a.distance(from: low, to: high)
    let mid = a.index(low, offsetBy: dist/2)
    mergeSort(&a, from: low, to: mid)
    mergeSort(&a, from: a.index(mid, offsetBy: 1), to: high)
    merge(&a, from: low, through: mid, to: high)
}

fileprivate func merge<T>(_ a: inout T, from low: T.Index, through mid: T.Index, to high: T.Index) where T: RandomAccessCollection, T: MutableCollection, T.Element: Comparable {
    var i = low
    var j = a.index(mid, offsetBy: 1)
    var tmp = Array<T.Element>()
    tmp.reserveCapacity(a.distance(from: low, to: high) + 1)
    while i <= mid && j <= high {
        if a[i] <= a[j] {
            tmp.append(a[i])
            a.formIndex(after: &i)
        } else {
            tmp.append(a[j])
            a.formIndex(after: &j)
        }
    }
    
    var start = i
    var end = mid
    if j <= high {
        start = j
        end = high
    }
    tmp.append(contentsOf: a[start...end])
    
    var current = low
    for element in tmp {
        a[current] = element
        a.formIndex(after: &current)
    }
}
