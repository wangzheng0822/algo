import Foundation

/// 冒泡排序
///
/// - Parameter elements: 数组
/// - Returns: 返回值
public func bubbleSort<T>(_ elements: [T]) ->[T] where T: Comparable {
    var array = elements
    guard array.count > 1 else {
        return array
    }
    for i in 0..<array.count {
        // 提前退出标志位
        var flag = false
        for j in 0..<array.count - i - 1 {
            if array[j] > array[j+1] {
                array.swapAt(j+1, j)
                // 此次冒泡有数据交换
                flag = true
            }
        }
        if (!flag) {
            break
        }
    }
    return array
}


/// 插入排序
///
/// - Parameter elements: 数组
/// - Returns: 返回值
public func insertionSort<T>(_ elements: [T]) -> [T] where T: Comparable {
    var array = elements
    guard array.count > 1 else {
        return array
    }
    for i in 1..<array.count {
        let value = array[i]
        var j = i - 1;
        // 查找要插入的位置并移动数据
        for p in (0...j).reversed() {
            j = p
            if array[p] > value {
                array[p+1] = array[p]
            } else {
                break
            }
        }
        array[j+1] = value
    }
    return array
}


/// 选择排序
///
/// - Parameter elements: 数组
/// - Returns: 返回值
public func selectionSort<T>(_ elements: [T]) -> [T] where T: Comparable {
    var array = elements
    guard array.count > 1 else {
        return array
    }
    for i in 0..<array.count {
        // 查找最小值
        var minIndex = i
        var minValue = array[i]
        for j in i..<array.count {
            if array[j] < minValue {
                minValue = array[j]
                minIndex = j
            }
        }
        // 交换
        array.swapAt(i, minIndex)
    }
    return array
}

