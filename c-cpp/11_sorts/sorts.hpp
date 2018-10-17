/**
 * Created by Liam Huang (Liam0205) on 2018/10/16.
 */

#ifndef SORTS_SORTS_HPP_
#define SORTS_SORTS_HPP_

#include <iterator>
#include <functional>

template <typename BidirIt,
          typename BinaryPred = std::less<typename std::iterator_traits<BidirIt>::value_type>>
void bubble_sort(BidirIt first, BidirIt last, BinaryPred comp = BinaryPred()) {
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

template <typename BidirIt,
          typename BinaryPred = std::less<typename std::iterator_traits<BidirIt>::value_type>>
void insertion_sort(BidirIt first,
                    BidirIt last,
                 BinaryPred comp = BinaryPred()) {
    if (std::distance(first, last) <= 1) { return; }
    for (auto it = first + 1; it != last; ++it) {
        const auto target = *it;
        auto       itt    = it;
        for (; std::distance(first, itt) > 0 and comp(target, *(itt - 1)); --itt) {
            *itt = *(itt - 1);
        }
        *itt = target;
    }
}

template <typename BidirIt,
          typename BinaryPred = std::less<typename std::iterator_traits<BidirIt>::value_type>>
void selection_sort(BidirIt first,
                    BidirIt last,
                 BinaryPred comp = BinaryPred()) {
    if (std::distance(first, last) <= 1) { return; }
    for (auto it = first; it != last - 1; ++it) {
        auto tag = it;
        for (auto itt = it + 1; itt != last; ++itt) {
            if (comp(*itt, *tag)) {
                tag = itt;
            }
        }
        if (tag != it) {
            std::swap(*it, *tag);
        }
    }
}

template <typename BidirIt,
          typename BinaryPred = std::less<typename std::iterator_traits<BidirIt>::value_type>>
void bubble_down_sort(BidirIt first, BidirIt last, BinaryPred comp = BinaryPred()) {
    if (std::distance(first, last) <= 1) { return; }
    for (auto it = first; it != last; ++it) {
        for (auto itt = it + 1; itt != last; ++itt) {
            if (comp(*itt, *it)) {
                std::swap(*it, *itt);
            }
        }
    }
}
#endif  // SORTS_SORTS_HPP_
