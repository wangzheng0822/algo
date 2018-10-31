/**
 * Created by Liam Huang (Liam0205) on 2018/10/30.
 */

#include <iostream>
#include <map>
#include <string>

#include "skiplist_tr.hpp"

int main() {
    // 1. UT for skiplist_detail::random_level
    skiplist_detail::random_level<size_t> rl(5, 0.5);
    std::map<size_t, size_t>    hist;
    for (size_t i = 0; i != 10000; ++i) {
        ++hist[rl()];
    }
    for (auto p : hist) {
        std::cout << p.first << ' ' << std::string(p.second / 100, '*') << '\n';
    }

    return 0;
}

