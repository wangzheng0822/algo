/**
 * Created by Liam Huang (Liam0205) on 2018/10/24.
 */

#ifndef BSEARCH_BSEARCH_HPP_
#define BSEARCH_BSEARCH_HPP_

#include <iterator>
#include <functional>

enum class BsearchPolicy { FIRST, LAST, UNSPECIFIED };

template <typename IterT,
          typename ValueT = typename std::iterator_traits<IterT>::value_type,
          typename Compare = std::less<ValueT>>
IterT bsearch(IterT first,
              IterT last,
             ValueT target,
            Compare comp,
      BsearchPolicy policy = BsearchPolicy::UNSPECIFIED) {
    IterT result = last;
    while (std::distance(first, last) > 0) {
        IterT mid = first + std::distance(first, last) / 2;
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
    return result;
}

template <typename IterT,
          typename ValueT = typename std::iterator_traits<IterT>::value_type>
IterT bsearch(IterT first,
              IterT last,
             ValueT target,
      BsearchPolicy policy = BsearchPolicy::UNSPECIFIED) {
	return bsearch(first, last, target, std::less<ValueT>(), policy);
}

#endif  // BSEARCH_BSEARCH_HPP_

