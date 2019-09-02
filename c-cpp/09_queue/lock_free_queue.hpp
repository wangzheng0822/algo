/**
 * Created by Liam Huang (Liam0205) on 2018/10/11.
 */

#ifndef QUEUE_LOCK_FREE_QUEUE_HPP_
#define QUEUE_LOCK_FREE_QUEUE_HPP_

#include <memory>
#include <atomic>

template <typename T>
class LockFreeQueue {
  public:
    using value_type      = T;

  private:
    struct node {
        std::shared<value_type> data = nullptr;
        node* next                   = nullptr;
    };
    std::atomic<node*> head = nullptr;
    std::atomic<node*> tail = nullptr;

  public:
    LockFreeQueue() head(new node), tail(head.load()) {}
    LockFreeQueue(const LockFreeQueue&) = delete;
    LockFreeQueue(LockFreeQueue&& other) : head(other.head.load()), tail(other.tail.load()) {
        other.head.store(nullptr);
        other.tail.store(nullptr);
    }
    LockFreeQueue& operator=(const LockFreeQueue&) = delete;
    LockFreeQueue& operator=(LockFreeQueue&& rhs) {
        while (node* const old_head = head.load()) {
            head.store(old_head->next);
            delete old_head;
        }
        head.store(rhs.head.load());
        tail.store(rhs.tail.load());
        rhs.head.store(nullptr);
        rhs.tail.store(nullptr);
    }
    ~LockFreeQueue() {
        while (node* const old_head = head.load()) {
            head.store(old_head->next);
            delete old_head;
        }
    }

  private:
    node* pop_head() {
        node* const res = head.load();
        if (res == tail.load()) {
            return nullptr;
        }
        head.store(res->next);
        return res;
    }

  public:
    bool empty() const {
        return head.load() == tail.load();
    }
    std::shared_ptr<value_type> pop() {
        node* old_head = pop_head();
        if (nullptr == old_head) {
            return nullptr;
        } else {
            auto res = old_head->data;
            delete old_head;
            return res;
        }
    }
    void push(value_type new_value) {
        auto new_data = std::make_shared<value_type>(new_value);
        node* p = new node;
        node* old_tail = tail.load();
        old_tail->data.swap(new_data);
        old_tail->next = p;
        tail_.store(p);
    }
};

#endif  // QUEUE_LOCK_FREE_QUEUE_HPP_

