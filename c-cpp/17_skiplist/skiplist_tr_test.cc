/**
 * Created by Liam Huang (Liam0205) on 2018/10/30.
 */
#include <assert.h>

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

    // 2. UT for skiplist(), init(), size(), empty()
    skiplist<std::string> sl_default;
    assert(sl_default.empty());
    return 0;
}

