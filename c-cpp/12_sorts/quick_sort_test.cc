/**
 * Created by Liam Huang (Liam0205) on 2018/10/17.
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "quick_sort.hpp"

void test_quick_sort(std::vector<int> test_data) {
    quick_sort(test_data.begin(), test_data.end());
    std::transform(test_data.begin(), test_data.end(),
            std::ostream_iterator<int>(std::cout, " "), [](int i){ return i; });
    std::cout << '\n';
}

int main() {
    test_quick_sort({-3, -1, 1, -2, -3, 0, -3, 100, 1, 1, -100});
    test_quick_sort({1, 1, 1});
    test_quick_sort({1, 0, -1});
    test_quick_sort({1});
    return 0;
}

