/**
 * Created by Liam Huang (Liam0205) on 2018/10/16.
 */

#ifndef SORTS_SORTS_HPP_
#define SORTS_SORTS_HPP_

#include <iterator>

template <typename RandomIt>
void bubble_sort(RandomIt first, RandomIt last) {
    if (std::distance(first, last) <= 1) { return; }
    for (auto it = first; it != last; ++it) {}
}

#endif  // SORTS_SORTS_HPP_
