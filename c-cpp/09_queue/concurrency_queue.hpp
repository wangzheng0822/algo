/**
 * Created by Liam Huang (Liam0205) on 2018/10/11.
 */

#ifndef QUEUE_CONCURRENCY_QUEUE_HPP_
#define QUEUE_CONCURRENCY_QUEUE_HPP_

#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>

template <typename T>
class ConcurrencyQueue {
  public:
    using value_type      = T;
    using container_type  = std::queue<value_type>;
    using size_type       = typename container_type::size_type;

  private:
    container_type container_;
    mutable std::mutex mutex_;
    std::condition_variable container_cond_;

  public:
    ConcurrencyQueue() = default;
    ConcurrencyQueue(const ConcurrencyQueue&) = default;
    ConcurrencyQueue(ConcurrencyQueue&&) = default;
    ConcurrencyQueue& operator=(const ConcurrencyQueue&) = default;
    ConcurrencyQueue& operator=(ConcurrencyQueue&&) = default;

  private:
    bool empty_() const { return container_.empty(); }

  public:
    bool empty() const {
        std::lock_guard<std::mutex> lg(mutex_);
        return container_.empty();
    }
    void push(value_type item) {
        std::lock_guard<std::mutex> lg(mutex_);
        container_.push(std::move(item));
        container_cond_.notify_one();
    }
    void wait_and_pop(value_type& out) {
        std::unique_lock<std::mutex> lk(mutex_);
        while (empty_()) {
            container_cond_.wait(lk)
        }
        out = std::move(container_.front());
        container_.pop();
    }
    std::shared_ptr<value_type> wait_and_pop() {
        std::unique_lock<std::mutex> lk(mutex_);
        while (empty_()) {
            container_cond_.wait(lk)
        }
        auto res = std::make_shared<value_type>(std::move(container_.front()));
        container_.pop();
        return res;
    }
    bool try_pop(value_type& out) {
        std::lock_guard<std::mutex> lg(mutex_);
        if (empty_()) {
            return false;
        } else {
            out = std::move(container_.front());
            container_.pop();
            return true;
        }
    }
    std::shared_ptr<value_type> try_pop() {
        std::lock_guard<std::mutex> lg(mutex_);
        if (empty_()) {
            return nullptr;
        } else {
            auto res = std::make_shared<value_type>(std::move(container_.front()));
            container_.pop();
            return res;
        }
    }
};

#endif  // QUEUE_CONCURRENCY_QUEUE_HPP_

