/**
 * Created by Liam Huang (Liam0205) on 2018/10/30.
 */

#ifndef SKIPLIST_SKIPLIST_TR_HPP_
#define SKIPLIST_SKIPLIST_TR_HPP_

#ifdef LIAM_UT_DEBUG_
#include <assert.h>
#include <iostream>
#endif

#include <set>
#include <vector>
#include <list>
#include <functional>
#include <type_traits>
#include <random>
#include <limits>
#include <algorithm>
#include <initializer_list>
#include <iterator>

namespace skiplist_detail {
template <typename Key, typename Value>
struct InternalNode {
    using iterator = typename std::list<InternalNode>::iterator;
    const Key             key;
    std::multiset<Value>  values;
    std::vector<iterator> forwards;

    InternalNode() = delete;
    explicit InternalNode(const Key& k) : key(k) {}
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
    size_type                                        max_lv_ = 16;
    double                                           prob_   = 0.5;
    mutable skiplist_detail::random_level<size_type> rl_;
    container                                        cont_;

  public:
    skiplist() : rl_(max_lv_, prob_) {
        init_internally();
    }
    explicit skiplist(const size_type max_lv, const double prob = 0.5)
        : max_lv_(max_lv), prob_(prob), rl_(max_lv_, prob_) {
        init_internally();
    }
    skiplist(skiplist&& other) = default;
    skiplist& operator=(skiplist&& other) = default;
    ~skiplist() = default;
    template <typename InputIt>
    skiplist(InputIt first, InputIt last) : skiplist() {
        using value_type_in_iter = typename std::iterator_traits<InputIt>::value_type;
        static_assert(std::is_same<value_type, value_type_in_iter>::value,
                "STATIC ASSERT FAILED! Value in InputIt should be the same to value_type.");
        for (InputIt i = first; i != last; ++i) {
            insert(*i);
        }
    }
    skiplist(std::initializer_list<value_type> init) : skiplist(init.begin(), init.end()) {}

  private:  // noncopyable
    skiplist(const skiplist&) = delete;
    skiplist& operator=(const skiplist&) = delete;

  private:
    void init_internally() {
        const hash_type tail_key = std::numeric_limits<hash_type>::max();
        node_type tail(tail_key);
        tail.forwards.resize(max_lv_);
        std::fill(tail.forwards.begin(), tail.forwards.end(), cont_.end());
        cont_.insert(cont_.begin(), std::move(tail));

        const hash_type head_key = std::numeric_limits<hash_type>::min();
        node_type head(head_key);
        head.forwards.resize(max_lv_);
        cont_.insert(cont_.begin(), std::move(head));
        std::fill(cont_.begin()->forwards.begin(), cont_.begin()->forwards.end(),
                std::next(cont_.begin()));

#ifdef LIAM_UT_DEBUG_
        assert(cont_.begin()->key == head_key);
        for (auto it : cont_.begin()->forwards) {
            assert(it->key == tail_key);
        }
        for (auto it : std::next(cont_.begin())->forwards) {
            assert(it == cont_.end());
        }
        std::cerr << "all assert in init() success!\n";
#endif

        return;
    }

  public:
    size_type size() const {
        return cont_.size() - 2;
    }
    bool empty() const {
        return size() == 0;
    }
};

#endif  // SKIPLIST_SKIPLIST_TR_HPP_

