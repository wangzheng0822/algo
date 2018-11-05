/**
 * Created by Liam Huang (Liam0205) on 2018/10/26.
 */

#ifndef SORTS_BUCKET_SORT_HPP_
#define SORTS_BUCKET_SORT_HPP_

#include <iterator>
#include <functional>
#include <algorithm>
#include <vector>

template <size_t BucketSize,
          typename IterT,
          typename T = typename std::iterator_traits<IterT>::value_type,
          typename Compare = std::less<T>>
void bucket_sort(IterT first, IterT last, Compare comp = Compare()) {
    const T min = *std::min_element(first, last), max = *std::max_element(first, last);
    const T range = max + 1 - min;
    const size_t bucket_num = (range - 1) / BucketSize + 1;

    std::vector<std::vector<T>> buckets(bucket_num);
    for (auto b : buckets) {
        b.reserve(2 * BucketSize);
    }

    for (IterT i = first; i != last; ++i) {
        size_t idx = (*i - min) / BucketSize;
        buckets[idx].emplace_back(*i);
    }

    IterT dest = first;
    for (auto b : buckets) {
        std::sort(b.begin(), b.end(), comp);
        std::copy(b.begin(), b.end(), dest);
        dest += b.size();
    }

    return;
}

#endif  // SORTS_BUCKET_SORT_HPP_

