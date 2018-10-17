#include <iostream>
#include <vector>

#include "sorts.hpp"

int main() {
    std::vector<int> a{1, 2, 3, 0};
    bubble_sort(a.begin(), a.end());
    for (auto i : a) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
