/**
 * Created by Liam Huang (Liam0205) on 2018/10/29.
 */

#ifndef SKIPLIST_SKIPLIST_HPP_
#define SKIPLIST_SKIPLIST_HPP_

#include <functional>
#include <type_traits>
#include <vector>
#include <chrono>
#include <random>
#include <initializer_list>

template <typename Value>
class skiplist {
  public:
    using value_type = Value;
    using hash_type  = std::hash<value_type>;
    using key_type   = std::result_of_t<Hash()(value_type)>>;
    using size_type  = size_t;

  private:
    struct InternalNode {
        value_type     value;
        const key_type key;
        std::vector<InternalNode*> forwards;  // pointers to successor nodes

        InternalNode(value_type&& v, const size_type lv)
            : value(v), key(Hash()(value)), forwards(lv, nullptr) {}
    };
    using node_type = InternalNode;

  private:
    const size_type MAX_LEVEL                          = 16;
    const double PROBABILITY                           = 0.5;
    mutable size_type level_count                      = 1;
    const unsigned int seed                            =
        std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator               = std::default_random_engine(seed);
    std::binomial_distribution<size_type> distribution =
        std::binomial_distribution<size_type>(MAX_LEVEL, PROBABILITY);

  public:
    skiplist() : container_type() {}
    skiplist(size_type count, const_reference value);
    skiplist(const skiplist& other);
    skiplist(const skiplist& other, const allocator_type& alloc);
    skiplist(skiplist&& other);
    skiplist(skiplist&& other, const allocator_type& alloc);
    skiplist(std::initializer_list<value_type> init);
    ~skiplist() {}

  public:
    skiplist& operator=(const skiplist& other);
    skiplist& operator=(skiplist&& other);

  private:
    inline size_type get_random_level() { return distribution(generator); }

  public:
    const value_type& find(const value_type& target);
    void  insert(const value_type& value);
    void  erase(const value_type& value);
};

#endif  // SKIPLIST_SKIPLIST_HPP_


