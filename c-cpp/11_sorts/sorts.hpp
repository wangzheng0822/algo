/**
 * Created by Liam Huang (Liam0205) on 2018/10/16.
 */

#ifndef SORTS_SORTS_HPP_
#define SORTS_SORTS_HPP_

#include <iterator>
#include <functional>

template <typename FrwdIt,
          typename BinaryPred = std::less<typename std::iterator_traits<FrwdIt>::value_type>>
void bubble_sort(FrwdIt first, FrwdIt last, BinaryPred comp = BinaryPred()) {
    if (std::distance(first, last) <= 1) { return; }
    bool flag = true;
    for (auto it = first; flag and it != last; ++it) {
        flag = false;
        for (auto itt = first; itt != last - std::distance(first, it) - 1; ++itt) {
            if (comp(*(itt + 1), *itt)) {
                std::swap(*itt, *(itt + 1));
                flag = true;
            }
        }
    }
}

#endif  // SORTS_SORTS_HPP_
