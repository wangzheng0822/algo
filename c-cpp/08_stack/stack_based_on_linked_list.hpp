/**
 * 基于链表实现的栈。
 *
 * Author: Liam Huang (Liam0205)
 */

#ifndef STACK_STACK_BASED_ON_LINKED_LIST_HPP_
#define STACK_STACK_BASED_ON_LINKED_LIST_HPP_

#include <memory>
#include "linked_list.h"

template <typename T>
class Stack {
  public:
    using value_type = T;
    using node_type  = typename Node<value_type>::ptr_t;

  private:
    node_type top_   = nullptr;

  public:
    bool empty(void) const {
        return nullptr == top_;
    }
    void push(const value_type& value) {
        auto node = std::make_shared<node_type>(value);
        if (this->empty()) {
            top_ = node;
        } else {
            node->next = top_;
            top_ = node;
        }
    }
    value_type top(void) const {
        if (not this->empty()) {
            return top_->data;
        } else {
            throw "Fetch data from empty stack!";
        }
    }
    void pop(void) {
        if (not this->empty()) {
            top_ = top_->next;
            return;
        } else {
            throw "Pop from empty stack!";
        }
    }
};

#endif
