/**
 * Created by Liam Huang (Liam0205) on 2018/10/30.
 */

#include <iostream>
#include <string>

#include "skiplist.hpp"

int main() {
    // 1. Initialize a skip list for test
    // * default constructor
    // * constructor with initializer list
    // * insert
    skiplist<std::string> ss{"1", "2", "3", "4", "5"};

    // 1a. show
    // * print
    ss.print(std::cout);
    std::cout << std::endl;

    // 2. move construction
    // * move constructor
    skiplist<std::string> s(std::move(ss));

    // 2a. show
    // * print
    s.print(std::cout);
    std::cout << std::endl;

    // 3.a find something doesn't exist.
    // * find
    auto f = s.find("0");
    if (!f.empty()) {
        std::cout << "Node found!\nvalue: " << f << '\n';
    } else {
        std::cout << "Node NOT found!\n";
    }

    // 3.b find something does exist.
    // * find
    auto ff = s.find("1");
    if (!ff.empty()) {
        std::cout << "Node found!\tvalue: " << ff << '\n';
    } else {
        std::cout << "Node NOT found!\n";
    }

    // 4. insert() - reassign
    s.insert("TEST");

    // 4a. print()
    s.print(std::cout);
    std::cout << std::endl;

    // 5. erase()
    s.erase("TEST");

    // 5a. print();
    s.print(std::cout);
    std::cout << std::endl;

    std::cout << "\nDone!\n";

    return 0;
    // 6. destructor
}
