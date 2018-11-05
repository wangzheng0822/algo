/**
 * Created by Liam Huang (Liam0205) on 2018/10/26.
 */

#include <iostream>
#include <vector>
#include <functional>

#include "bucket_sort.hpp"

template <size_t BucketSize,
          typename Container,
          typename T = typename Container::value_type,
          typename Compare = std::less<T>>
void test_bucket_sort(Container cont, Compare comp = Compare()) {
    bucket_sort<BucketSize>(cont.begin(), cont.end(), comp);
    std::transform(cont.begin(), cont.end(), std::ostream_iterator<T>(std::cout, " "),
            [](T i){ return i; });
    std::cout << std::endl;
}

int main() {
    std::vector<int> test{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9};

    test_bucket_sort<2>(test);  // 1 1 2 3 3 4 5 5 5 6 7 8 9 9 9
    test_bucket_sort<3>(test);  // 1 1 2 3 3 4 5 5 5 6 7 8 9 9 9
    test_bucket_sort<4>(test);  // 1 1 2 3 3 4 5 5 5 6 7 8 9 9 9
    test_bucket_sort<5>(test);  // 1 1 2 3 3 4 5 5 5 6 7 8 9 9 9
    test_bucket_sort<6>(test);  // 1 1 2 3 3 4 5 5 5 6 7 8 9 9 9

    return 0;
}

