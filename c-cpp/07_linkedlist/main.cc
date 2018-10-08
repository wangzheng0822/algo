#include <memory>
#include "linked_list.h"
#include "linked_list_algo.hpp"

int main() {
    typename Node<int>::ptr_t head = nullptr;
    head = std::make_shared<Node<int>>(1);
    head->next = std::make_shared<Node<int>>(2);
    head->next->next = std::make_shared<Node<int>>(3);
    // head->next->next->next = head->next;  // circle

    auto print_node = [&](typename Node<int>::ptr_t node) { std::cout << node->data << ' '; };

    traverse<int>(head, print_node);
    std::cout << std::endl;
    auto mid = find_middle_node<int>(head);
    traverse<int>(mid, print_node);
    std::cout << std::endl;

    return 0;
}
