#include <iostream>
#include <vector>

#include "sorts.hpp"

int main() {
    const std::vector<int> test_data{1, 2, 3, 0};

    std::vector<int> a(test_data.begin(), test_data.end());
    bubble_sort(a.begin(), a.end());
    for (auto i : a) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::vector<int> b(test_data.begin(), test_data.end());
    bubble_sort(b.begin(), b.end());
    for (auto i : b) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
