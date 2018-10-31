/**
 * Created by Liam Huang (Liam0205) on 2018/10/30.
 */

#ifndef SKIPLIST_SKIPLIST_TR_HPP_
#define SKIPLIST_SKIPLIST_TR_HPP_

#include <set>
#include <vector>
#include <list>
#include <functional>
#include <type_traits>
#include <random>

namespace skiplist_detail {
template <typename Key, typename Value>
struct InternalNode {
    using iterator = typename std::list<InternalNode>::iterator;
    const Key             key;
    std::multiset<Value>  values;
    std::vector<iterator> forwards;
};

template <typename IntType>
class random_level {
  private:
    mutable std::random_device                  rd;
    mutable std::mt19937                        gen = std::mt19937(rd());
    mutable std::binomial_distribution<IntType> dist;

  public:
    random_level(IntType max_level, double prob) : dist(max_level - 1, prob) {}
    inline IntType operator()() const { return dist(gen); }
};
}  // namespace skiplist_detail

template <typename Value,
          typename Compare = std::less<Value>,
          typename Hash = std::hash<Value>>
class skiplist {
  public:
    using value_type = Value;
    using compare    = Compare;
    using size_type  = size_t;
    using hasher     = Hash;
    using hash_type  = typename Hash::result_type;
    using node_type  = skiplist_detail::InternalNode<hash_type, value_type>;
    using container  = std::list<node_type>;
    using iterator   = typename container::iterator;
    static_assert(std::is_same<iterator, typename node_type::iterator>::value,
            "STATIC ASSERT FAILED! iterator type differs.");

  private:
    size_type                       max_lv_ = 16;
    double                          prob_   = 0.5;
    mutable random_level<size_type> rl_;

  public:
    skiplist() : rl_(max_lv_, prob_) {}
};

#endif  // SKIPLIST_SKIPLIST_TR_HPP_

