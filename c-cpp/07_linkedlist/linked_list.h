/**
 * 单链表
 *
 * Author: Liam Huang (Liam0205)
 */

#ifndef LINKEDLIST_LINKED_LIST_H_
#define LINKEDLIST_LINKED_LIST_H_

#include <memory>

template <typename T>
struct Node {
    using ptr_t = std::shared_ptr<Node<T>>;
    T     data;
    ptr_t next;

    Node(T data_) : data(data_), next(nullptr) {}
    Node() : next(nullptr) {}
};

#endif  // LINKEDLIST_LINKED_LIST_H_
