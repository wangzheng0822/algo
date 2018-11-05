/**
 * Created by Liam Huang (Liam0205) on 2018/10/24.
 */

#ifndef BSEARCH_BSEARCH_HPP_
#define BSEARCH_BSEARCH_HPP_

#include <iterator>
#include <functional>

// Liam Huang: The algorithm works right with iterators that meet the ForwardIterator requirement,
//             but with a bad time complexity. For better performance, iterators should meet
//             the RandomAccessIterator requirement.
template <typename IterT,
          typename ValueT = typename std::iterator_traits<IterT>::value_type,
          typename Compare = std::less<ValueT>>
IterT bsearch(IterT first,
              IterT last,
             ValueT target,
            Compare comp = Compare()) {
    IterT result = last;
    while (std::distance(first, last) > 0) {
        IterT mid = first + std::distance(first, last) / 2;
        if (comp(*mid, target)) {
            first = mid + 1;
        } else if (comp(target, *mid)) {
            last = mid;
        } else {  // equal
            result = mid;
            break;
        }
    }
    return result;
}

#endif  // BSEARCH_BSEARCH_HPP_

