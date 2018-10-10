/**
 * Created by Liam Huang (Liam0205) on 2018/10/10.
 */

#ifndef QUEUE_ARRAY_QUEUE_HPP_
#define QUEUE_ARRAY_QUEUE_HPP_

template <typename T>
class ArrayQueue {
  private:
    T*     items_    = nullptr;
    size_t capacity_ = 0;
    size_t head_     = 0;
    size_t tail_     = 0;

  public:
    ArrayQueue() = default;
    ArrayQueue(size_t capacity) : capacity_(capacity) {
        items_ = new T[capacity];
    }
    ~ArrayQueue() {
        if (nullptr != items_) {
            delete[] items_;
            items_ = nullptr;
        }
    }
    ArrayQueue(const ArrayQueue& other) : capacity_(other.capacity_) {
        items_ = new T[capacity_];
        for (size_t i = other.head_; i != other.tail_; ++i) {
            enqueue(other.items_[i]);
        }
    }
    // TODO
    ArrayQueue& operator=(const ArrayQueue& rhs) {
        capacity_ = rhs.capacity_;
        items_ = new T[capacity_];
        for (size_t i = other.head_; i != other.tail_; ++i) {
            enqueue(other.items_[i]);
        }
    }
};

#endif  // QUEUE_ARRAY_QUEUE_HPP_
