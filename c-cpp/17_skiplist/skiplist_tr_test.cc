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

    // 2. UT for skiplist(), init_internally(), size(), empty()
    skiplist<std::string> sl_default;
    assert(sl_default.empty());
    // 2.1. UT for grow with abandon
    sl_default.grow(1);
    assert(sl_default.capability() == 4);
    // 2.2. UT for grow
    sl_default.grow(10);
    assert(sl_default.capability() == 1024);

    // 3. UT for constructor of initializer_list and InputIt, init_internally(), insert(),
    // find_predecessors()
    skiplist<std::string> sl{"hello", "world", "!"};
    assert(not sl.empty());
    assert(3 == sl.size());

    // 4. UT for find() find_helper()
    auto search = sl_default.find("nonexist");
    assert(search == sl_default.cend());
    assert(search == sl_default.end());
    search = sl.find("hello");
    assert(search != sl.cend());
    assert(search != sl.end());
    search = sl.find("nonexist");
    assert(search == sl.cend());
    assert(search == sl.end());

    // 5. UT for insert(), find_predecessors()
    // 5.1. UT for insert a already-exist item
    sl.insert("hello");
    search = sl.find("hello");
    assert(search != sl.cend());
    assert(search != sl.end());
    // 5.2. UT for insert a new incoming item
    search = sl.find("now exist");
    assert(search == sl.cend());
    assert(search == sl.end());
    sl.insert("now exist");
    search = sl.find("now exist");
    assert(search != sl.cend());
    assert(search != sl.end());

    // 6. UT for erase(), find_predecessors()
    sl.insert("hello");
    sl.insert("hello");
    sl.insert("hello");
    sl.insert("hello");
    // 6.1. UT for erase single item
    sl.erase("hello", erase_policy::SINGLE);
    search = sl.find("hello");
    assert(search != sl.cend());
    assert(search != sl.end());
    // 6.2. UT for erase all items
    sl.erase("hello", erase_policy::ALL);
    search = sl.find("hello");
    assert(search == sl.cend());
    assert(search == sl.end());
    // 6.3 UT for erase non-exist item
    sl.erase("nonexist");

    // 7. UT for insert() behind erase()
    // 7.1. different word
    sl.insert("world");
    search = sl.find("world");
    assert(search != sl.cend());
    assert(search != sl.end());
    assert(search->values.count("world") == 2);
    // 7.1. same word, also UT for grow()
    search = sl.find("hello");
    assert(search == sl.cend());
    assert(search == sl.end());
    sl.insert("hello");
    sl.insert("hello");
    sl.insert("hello");
    sl.insert("hello");
    sl.insert("hello");
    search = sl.find("hello");
    assert(search != sl.cend());
    assert(search != sl.end());
    assert(search->values.count("hello") == 5);

    return 0;
    // 8. UT for ~skiplist()
}

