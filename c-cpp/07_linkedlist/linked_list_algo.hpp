/**
 * 0) 遍历单链表
 * 1) 单链表反转
 * 2) 链表中环的检测
 * 3) 两个有序的链表合并
 * 4) 删除链表倒数第n个结点
 * 5) 求链表的中间结点
 *
 * Author: Liam Huang (Liam0205)
 */

#ifndef LINKEDLIST_LINKED_LIST_ALGO_HPP_
#define LINKEDLIST_LINKED_LIST_ALGO_HPP_

#include <memory>

#include "linked_list.h"

template <typename T, typename UnaryFunc>
void traverse(typename Node<T>::ptr_t head, UnaryFunc do_traverse) {
    auto sentry  = std::make_shared<Node<T>>();
    sentry->next = head;
    decltype(sentry) work = sentry;
    while (work = work->next) {
        do_traverse(work);
    }
}

template <typename T>
typename Node<T>::ptr_t reverse(typename Node<T>::ptr_t head) {
    if (nullptr == head or nullptr == head->next) {
        return head;
    }
    decltype(head) prev = nullptr, curr = head, next = head->next;
    while (nullptr != next) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    curr->next = prev;
    return curr;
}

template <typename T>
bool check_circle(typename Node<T>::ptr_t head) {
    if (nullptr == head or nullptr == head->next) {
        return false;
    }
    decltype(head) slow = head, fast = head;
    while (nullptr != fast and nullptr != fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

template <typename T>
typename Node<T>::ptr_t merge_two_sorted_lists(typename Node<T>::ptr_t lhs,
                                               typename Node<T>::ptr_t rhs) {
    if (nullptr == lhs) { return rhs; }
    if (nullptr == rhs) { return lhs; }

    decltype(lhs) l = lhs, r = rhs, head = nullptr, work = nullptr;

    if (l->data < r->data) {
        head = l;
        l = l->next;
    } else {
        head = r;
        r = r->next;
    }
    work = head;

    while (nullptr != l and nullptr != r) {
        if (l->data < r->data) {
            work->next = l;
            l = l->next;
        } else {
            work->next = r;
            r = r->next;
        }
        work = work->next;
    }

    if (nullptr != l) {
        work->next = l;
    } else {
        work->next = r;
    }

    return head;
}

template <typename T>
typename Node<T>::ptr_t deleth_last_Kth(typename Node<T>::ptr_t head,
                                                         size_t n) {
    decltype(head) sentry = std::make_shared<Node<T>>();
    sentry->next = head;
    decltype(head) prev = sentry, curr = sentry->next, fast = sentry->next;
    for (size_t i = 0; i != n; ++i) {
        if (nullptr != fast) {
            fast = fast->next;
        } else {
            return sentry->next;
        }
    }
    while (nullptr != fast) {
        prev = curr;
        curr = curr->next;
        fast = fast->next;
    }
    prev->next = curr->next;
    return sentry->next;
}

template <typename T>
typename Node<T>::ptr_t find_middle_node(typename Node<T>::ptr_t head) {
    if (nullptr == head or nullptr == head->next) {
        return head;
    }
    decltype(head) slow = head, fast = head;
    while (nullptr != fast and nullptr != fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return nullptr;
        }
    }
    return slow;
}

#endif  // LINKEDLIST_LINKED_LIST_ALGO_HPP_
