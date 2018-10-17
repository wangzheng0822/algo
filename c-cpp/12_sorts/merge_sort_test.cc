/**
 * Created by Liam Huang (Liam0205) on 2018/10/17.
 */

#include <iostream>
#include <vector>
#include "merge_sort.hpp"

int main() {
    const std::vector<int> test_data{0, -1, 3, 190, -500};

    std::vector<int> a{test_data};
    merge_sort(a.begin(), a.end());
    for (auto i : a) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::vector<int> b{test_data};
    inplace_merge_sort(b.begin(), b.end());
    for (auto i : b) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}

