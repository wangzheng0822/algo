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
#include <limits>
#include <iostream>

template <typename Value>
class skiplist {
  public:
    using value_type = Value;
    using hash_type  = std::hash<value_type>;
    using key_type   = typename hash_type::result_type;
    using size_type  = size_t;

  private:
    struct InternalNode {
        value_type     value;
        const key_type key;
        std::vector<InternalNode*> forwards;  // pointers to successor nodes

        InternalNode(const key_type& k, const size_type lv)
            : value(), key(k), forwards(lv, nullptr) {}
        InternalNode(const value_type& v, const size_type lv)
            : value(v), key(hash_type()(value)), forwards(lv, nullptr) {}
    };
    using node_type = InternalNode;

  private:
    const size_type MAX_LEVEL                          = 16;
    const double PROBABILITY                           = 0.5;
    const unsigned int seed                            =
        std::chrono::system_clock::now().time_since_epoch().count();
    mutable
    std::default_random_engine generator               = std::default_random_engine(seed);
    mutable
    std::binomial_distribution<size_type> distribution =
        std::binomial_distribution<size_type>(MAX_LEVEL - 1, PROBABILITY);
    node_type* head                                    = nullptr;
    node_type* nil                                     = nullptr;
    static const value_type default_value;

  public:
    skiplist() {
        key_type head_key = std::numeric_limits<key_type>::min();
        key_type nil_key  = std::numeric_limits<key_type>::max();
        head = new node_type(head_key, MAX_LEVEL);
        nil  = new node_type(nil_key,  MAX_LEVEL);
        std::fill(head->forwards.begin(), head->forwards.end(), nil);
    }
    skiplist(std::initializer_list<value_type> init) : skiplist() {
        for (const value_type& v : init) {
            insert(v);
        }
    }
    skiplist(const skiplist& other) = delete;
    skiplist(skiplist&& other) :
        MAX_LEVEL(std::move(other.MAX_LEVEL)),
        PROBABILITY(std::move(other.PROBABILITY)),
        seed(std::move(other.seed)),
        generator(std::move(other.generator)),
        distribution(std::move(other.distribution)),
        head(other.head),
        nil(other.nil) {
        other.head = nullptr;
        other.nil  = nullptr;
    }
    ~skiplist() {
        node_type* node = head;
        while (nullptr != node and nullptr != node->forwards[0]) {
            node_type* tmp = node;
            node = node->forwards[0];
            delete tmp;
        }
        delete node;
    }
    skiplist& operator=(const skiplist& other) = delete;
    skiplist& operator=(skiplist&& other)      = delete;

  private:
    inline size_type get_random_level() const {
        return distribution(generator);
    }
    static size_type get_node_level(const node_type* node) {
        return node->forwards.size();
    }
    static node_type* make_node(const value_type& v, const size_type lv) {
        return new node_type(v, lv);
    }
    /**
     * @brief   returns a pointer to the first node such that
     *          node->key == hash_type()(v) and node->value == v.
     */
    node_type* get_first_equal(const value_type& v) const {
        const key_type target = hash_type()(v);
        node_type* x = head;
        for (size_type i = get_node_level(head); i > 0; --i) {
            while (x->forwards[i - 1]->key < target or
                    x->forwards[i - 1]->key == target and x->forwards[i - 1]->value != v) {
                x = x->forwards[i - 1];
            }
        }
        return x->forwards[0];
    }
    /**
     * @brief   returns a collection of nodes.
     *          returns[i] is the pointer to the last node at level i + 1
     *          such that returns[i]->key < hash_type()(v) or
     *          returns[i]->key == hash_type()(v) but returns[i]->value != v.
     */
    std::vector<node_type*> get_predecessors(const value_type& v) const {
        const key_type target = hash_type()(v);
        std::vector<node_type*> results(get_node_level(head), nullptr);
        node_type* x = head;
        for (size_type i = get_node_level(head); i > 0; --i) {
            while (x->forwards[i - 1]->key < target or
                    x->forwards[i - 1]->key == target and x->forwards[i - 1]->value != v) {
                x = x->forwards[i - 1];
            }
            results[i - 1] = x;
        }
        return results;
    }

  public:
    const value_type& find(const value_type& target) {
        node_type* x = get_first_equal(target);
        if (nullptr != x and nil != x and x->value == target) {
            return x->value;
        } else {
            return default_value;
        }
    }
    void  insert(const value_type& value) {
        std::vector<node_type*> preds       = get_predecessors(value);
        const size_type         new_node_lv = get_random_level();
        node_type*              new_node    = make_node(value, new_node_lv);
        for (size_type i = 0; i != new_node_lv; ++i) {
            new_node->forwards[i] = preds[i]->forwards[i];
            preds[i]->forwards[i] = new_node;
        }
    }
    void  erase(const value_type& value) {
        std::vector<node_type*> preds = get_predecessors(value);

        node_type* node               = preds[0]->forwards[0];
        if (node == nil or node->value != value) { return; }

        for (size_type i = 0; i != get_node_level(node); ++i) {
            preds[i]->forwards[i] = node->forwards[i];
        }
        delete node;
    }
    void  print(std::ostream& os) const {
        node_type* list = head->forwards[0];
        os << "{";

        while (list != nil) {
            os << "key: " << list->key << " value: " << list->value
               << " level: " << get_node_level(list);

            list = list->forwards[0];

            if (list != nil) os << " : ";

            os << "\n";
        }
        os << "}\n";
    }
};

template <typename Value>
const typename skiplist<Value>::value_type skiplist<Value>::default_value =
    typename skiplist<Value>::value_type();

#endif  // SKIPLIST_SKIPLIST_HPP_

