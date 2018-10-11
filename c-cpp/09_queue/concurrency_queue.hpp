/**
 * Created by Liam Huang (Liam0205) on 2018/10/11.
 */

#ifndef QUEUE_CONCURRENCY_QUEUE_HPP_
#define QUEUE_CONCURRENCY_QUEUE_HPP_

#include <queue>
#include <mutex>

template <typename T>
class ConcurrencyQueue {
  public:
    using value_type      = T;
    using container_type  = std::queue<value_type>;
    using size_type       = typename container_type::size_type;

  private:
    container_type container_;
    mutable std::mutex mutex_;

  public:
    ConcurrencyQueue() = default;
    ConcurrencyQueue(const ConcurrencyQueue&) = default;
    ConcurrencyQueue(ConcurrencyQueue&&) = default;
    ConcurrencyQueue& operator=(const ConcurrencyQueue&) = default;
    ConcurrencyQueue& operator=(ConcurrencyQueue&&) = default;

  private:
    bool empty() const { return container_.empty(); }
};

#endif  // QUEUE_CONCURRENCY_QUEUE_HPP_

