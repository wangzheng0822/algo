/**
 * Created by Liam Huang (Liam0205) on 2018/10/17.
 */

#include <iostream>
#include <vector>
#include "merge_sort.hpp"

int main() {
    std::vector<int> test_data{0, -1, 3, 190, -500};
    merge_sort(test_data.begin(), test_data.end());
    for (auto i : test_data) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}

