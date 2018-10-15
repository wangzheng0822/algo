/**
 * Created by Liam Huang (Liam0205) on 2018/10/10.
 */

#ifndef QUEUE_DYNAMIC_ARRAY_QUEUE_HPP_
#define QUEUE_DYNAMIC_ARRAY_QUEUE_HPP_

template <typename T>
class DynamicArrayQueue {
  private:
    T*     items_    = nullptr;
    size_t capacity_ = 0;
    size_t head_     = 0;
    size_t tail_     = 0;

  public:
    DynamicArrayQueue() = delete;
    DynamicArrayQueue(const size_t capacity) : capacity_(capacity) {
        items_ = new T[capacity_];
    }
    ~DynamicArrayQueue() {
        if (nullptr != items_) {
            delete[] items_;
            items_ = nullptr;
        }
    }
    DynamicArrayQueue(const DynamicArrayQueue& other) : capacity_(other.capacity_) {
        items_ = new T[capacity_];
        for (size_t i = other.head_; i != other.tail_; ++i) {
            enqueue(other.items_[i]);
        }
    }
    DynamicArrayQueue& operator=(const DynamicArrayQueue& rhs) {
        delete[] items_;
        head_     = 0;
        tail_     = 0;
        capacity_ = rhs.capacity_;
        items_    = new T[capacity_];
        for (size_t i = rhs.head_; i != rhs.tail_; ++i) {
            enqueue(rhs.items_[i]);
        }
        return *this;
    }
    DynamicArrayQueue(DynamicArrayQueue&& other) : items_(other.items_),
                                     capacity_(other.capacity_),
                                     head_(other.head_),
                                     tail_(other.tail_) {
        other.items_    = nullptr;
        other.capacity_ = 0;
        other.head_     = 0;
        other.tail_     = 0;
    }
    DynamicArrayQueue& operator=(DynamicArrayQueue&& rhs) {
        delete[] items_;
        items_        = rhs.items_;
        capacity_     = rhs.capacity_;
        head_         = rhs.head_;
        tail_         = rhs.tail_;
        rhs.items_    = nullptr;
        rhs.capacity_ = 0;
        rhs.head_     = 0;
        rhs.tail_     = 0;
        return *this;
    }

  public:
    void enqueue(T item) {
        if (capacity_ == tail_ - head_) {
            throw "Push data into a full queue!";
        }
        if (capacity_ == tail_) {
            // item transport
            for (size_t i = head_; i != tail_; ++i) {
                items_[i - head_] = items_[i];
            }
            tail_ = tail_ - head_;
            head_ = 0;
        }
        items_[tail_++] = item;
    }
    T head() const {
        if (head_ != tail_) {
            return items_[head_];
        } else {
            throw "Fetch data from an empty queue!";
        }
    }
    void dequeue() {
        if (head_ != tail_) {
            ++head_;
        } else {
            throw "Pop data from an empty queue!";
        }
    }

  public:
    template <typename UnaryFunc>
    void traverse(UnaryFunc do_traverse) {
        for (size_t i = head_; i != tail_; ++i) {
            do_traverse(items_[i]);
        }
    }
};

#endif  // QUEUE_DYNAMIC_ARRAY_QUEUE_HPP_
