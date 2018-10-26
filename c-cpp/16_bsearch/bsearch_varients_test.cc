/**
 * Created by Liam Huang (Liam0205) on 2018/10/26.
 */

#include <iostream>
#include <vector>

#include "bsearch_varients.hpp"

template <typename VecT, typename T = typename VecT::value_type>
void test_bsearch(const VecT& test,
                            T target,
                BsearchPolicy policy = BsearchPolicy::UNSPECIFIED) {
    auto it = bsearch(test.begin(), test.end(), target, policy);
    std::cout << std::distance(test.begin(), it) << std::endl;
}

int main() {
    std::vector<int> test{0, 0, 1, 2, 3, 4, 4, 5, 5, 5, 5, 5, 6, 8};  // std::less<int>()

    test_bsearch(test, 8);                                   // 14
    test_bsearch(test, -1);                                  // 14
    test_bsearch(test, 0);                                   // 0, 1
    test_bsearch(test, 0, BsearchPolicy::FIRST);             // 0
    test_bsearch(test, 0, BsearchPolicy::LAST);              // 1
    test_bsearch(test, 4);                                   // 5, 6
    test_bsearch(test, 4, BsearchPolicy::FIRST);             // 5
    test_bsearch(test, 4, BsearchPolicy::LAST);              // 6
    test_bsearch(test, 5);                                   // 7, 8, 9, 10, 11
    test_bsearch(test, 5, BsearchPolicy::FIRST);             // 7
    test_bsearch(test, 5, BsearchPolicy::LAST);              // 11
    test_bsearch(test, 7, BsearchPolicy::FIRST_NOT_LESS);    // 13
    test_bsearch(test, 7, BsearchPolicy::LAST_NOT_GREATER);  // 12
    test_bsearch(test, 7, BsearchPolicy::FIRST);             // 14
    test_bsearch(test, 8);                                   // 13
    test_bsearch(test, 8, BsearchPolicy::FIRST);             // 13
    test_bsearch(test, 8, BsearchPolicy::LAST);              // 13

    return 0;
}

