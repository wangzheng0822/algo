# 二分查找（下）

本节课讨论二分的各种变体。实际上在针对上一节的代码中，已经实现了两个变体。本次实现四个变体：

* 第一个等于给定值的元素
* 最后一个等于给定值的元素
* 第一个不小于给定值的元素
* 最后一个不大于给定值的元素

```cpp
/**
 * Created by Liam Huang (Liam0205) on 2018/10/26.
 */

#ifndef BSEARCH_BSEARCH_VARIENTS_HPP_
#define BSEARCH_BSEARCH_VARIENTS_HPP_

#include <iterator>
#include <functional>

enum class BsearchPolicy { UNSPECIFIED, FIRST, LAST, FIRST_NOT_LESS, LAST_NOT_GREATER };

// Liam Huang: The algorithm works right with iterators that meet the ForwardIterator requirement,
//             but with a bad time complexity. For better performance, iterators should meet
//             the RandomAccessIterator requirement.
template <typename IterT,
          typename ValueT = typename std::iterator_traits<IterT>::value_type,
          typename Compare>
IterT bsearch(IterT first,
              IterT last,
             ValueT target,
            Compare comp,
      BsearchPolicy policy = BsearchPolicy::UNSPECIFIED) {
    IterT result = last;
    while (std::distance(first, last) > 0) {
        IterT mid = first + std::distance(first, last) / 2;
        if (policy == BsearchPolicy::FIRST_NOT_LESS) {
            if (!comp(*mid, target)) {
                if (mid == first or comp(*(mid - 1), target)) {
                    result = mid;
                    break;
                } else {
                    last = mid;
                }
            } else {
                first = mid + 1;
            }
        } else if (policy == BsearchPolicy::LAST_NOT_GREATER) {
            if (comp(target, *mid)) {
                last = mid;
            } else {
                if (std::distance(mid, last) == 1 or comp(target, *(mid + 1))) {
                    result = mid;
                    break;
                } else {
                    first = mid + 1;
                }
            }
        } else {  // policy == UNSPECIFIED or FIRST or LAST
            if (comp(*mid, target)) {
                first = mid + 1;
            } else if (comp(target, *mid)) {
                last = mid;
            } else {  // equal
                if (policy == BsearchPolicy::FIRST) {
                    if (mid == first or comp(*(mid - 1), *mid)) {
                        result = mid;
                        break;
                    } else {
                        last = mid;
                    }
                } else if (policy == BsearchPolicy::LAST) {
                    if (std::distance(mid, last) == 1 or comp(*mid, *(mid + 1))) {
                        result = mid;
                        break;
                    } else {
                        first = mid + 1;
                    }
                } else {
                    result = mid;
                    break;
                }
            }
        }
    }
    return result;
}

template <typename IterT,
          typename ValueT = typename std::iterator_traits<IterT>::value_type,
          typename Compare = std::less<ValueT>>
IterT bsearch(IterT first,
              IterT last,
             ValueT target,
      BsearchPolicy policy = BsearchPolicy::UNSPECIFIED) {
        return bsearch(first, last, target, Compare(), policy);
}

#endif  // BSEARCH_BSEARCH_VARIENTS_HPP_
```
