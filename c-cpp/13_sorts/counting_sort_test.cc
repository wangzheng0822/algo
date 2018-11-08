/**
 * Created by Liam Huang (Liam0205) on 2018/10/26.
 */

#include <iostream>
#include <vector>
#include <functional>

#include "counting_sort.hpp"

template <typename Container,
          typename T = typename Container::value_type>
void test_counting_sort(Container cont) {
    counting_sort(cont.begin(), cont.end());
    std::transform(cont.begin(), cont.end(), std::ostream_iterator<T>(std::cout, " "),
            [](T i){ return i; });
    std::cout << std::endl;
}

int main() {
    // Liam Huang: pi for test
    const std::vector<int> test1{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3};
    const std::vector<int> test2{2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8, 3, 2, 7, 9};
    const std::vector<int> test3{5, 0, 2, 8, 8, 4, 1, 9, 7, 1, 6, 9, 3, 9, 9};
    const std::vector<int> test4{3, 7, 5, 1, 0, 5, 8, 2, 0, 9, 7, 4, 9, 4, 4};
    const std::vector<int> test5{5, 9, 2, 3, 0, 7, 8, 1, 6, 4, 0, 6, 2, 8, 6};

    test_counting_sort(test1);  // 1 1 2 3 3 3 4 5 5 5 6 7 8 9 9 9
    test_counting_sort(test2);  // 2 2 2 3 3 3 3 4 4 6 6 7 8 8 9
    test_counting_sort(test3);  // 0 1 1 2 3 4 5 6 7 8 8 9 9 9 9
    test_counting_sort(test4);  // 0 0 1 2 3 4 4 4 5 5 7 7 8 9 9
    test_counting_sort(test5);  // 0 0 1 2 2 3 4 5 6 6 6 7 8 8 9

    return 0;
}

