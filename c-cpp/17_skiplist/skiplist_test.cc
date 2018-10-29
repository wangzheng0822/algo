#include <iostream>
#include "skiplist.hpp"

int main() {
    skiplist<int> test{1, 2, 3, 4};
    for (auto i : test) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
