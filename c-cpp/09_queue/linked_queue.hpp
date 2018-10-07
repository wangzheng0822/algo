/**
 * Created by Liam Huang (Liam0205) on 2018/10/10.
 */

#ifndef QUEUE_LINKED_QUEUE_HPP_
#define QUEUE_LINKED_QUEUE_HPP_

#include <memory>

template <typename T>
struct Node {
    using ptr_t = std::shared_ptr<Node<T>>;
    T     data;
    ptr_t next;

    Node(T data_) : data(data_), next(nullptr) {}
    Node() : next(nullptr) {}
};

template <typename T>
class LinkedQueue {
  public:
    using node_type  = Node<T>;
    using node_ptr_t = typename node_type::ptr_t;

  private:
    node_ptr_t head_        = nullptr;
    node_ptr_t before_tail_ = nullptr;

  public:
    LinkedQueue()  = default;
    ~LinkedQueue() = default;
    LinkedQueue(const LinkedQueue& other) = default;
    LinkedQueue& operator=(const LinkedQueue& rhs) = default;
    LinkedQueue(LinkedQueue&& other) = default;
    LinkedQueue& operator=(LinkedQueue&& rhs) = default;

  public:
    void enqueue(T item) {
        if (nullptr == head_) {
            head_ = std::make_shared<node_type>(item);
            before_tail_ = head_;
        } else {
            before_tail_->next = std::make_shared<node_type>(item);
            before_tail_ = before_tail_->next;
        }
    }
    T head() const {
        if (nullptr != head_) {
            return head_->data;
        } else {
            throw "Fetch data from an empty queue!";
        }
    }
    void dequeue() {
        if (nullptr != head_) {
            head_ = head_->next;
            if (nullptr == head_) {
                before_tail_ = nullptr;
            }
        } else {
            throw "Pop data from an empty queue!";
        }
    }

  public:
    template <typename UnaryFunc>
    void traverse(UnaryFunc do_traverse) {
        for (node_ptr_t work = head_; nullptr != work; work = work->next) {
            do_traverse(work->data);
        }
    }
};

#endif  // QUEUE_LINKED_QUEUE_HPP_
