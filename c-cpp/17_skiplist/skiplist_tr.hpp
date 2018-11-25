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

enum class erase_policy { ALL, SINGLE };

template <typename Value,
          typename Hash = std::hash<Value>,
          size_t Factor = 2>
class skiplist {
  public:
    using value_type     = Value;
    using size_type      = size_t;
    using hasher         = Hash;
    using hash_type      = typename Hash::result_type;
    using compare        = std::less<hash_type>;
    using node_type      = skiplist_detail::InternalNode<hash_type, value_type>;
    using container      = std::list<node_type>;
    using iterator       = typename container::iterator;
    using const_iterator = typename container::const_iterator;
    static_assert(std::is_same<iterator, typename node_type::iterator>::value,
            "STATIC ASSERT FAILED! iterator type differs.");

  private:
    size_type                                        max_lv_ = 2;
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
        tail.forwards.resize(max_lv_, cont_.end());
        iterator tail_iter = cont_.insert(cont_.begin(), std::move(tail));

        const hash_type head_key = std::numeric_limits<hash_type>::min();
        node_type head(head_key);
        head.forwards.resize(max_lv_, tail_iter);
        cont_.insert(cont_.begin(), std::move(head));

#ifdef LIAM_UT_DEBUG_
        assert(cont_.begin()->key == head_key);
        for (auto it : cont_.begin()->forwards) {
            assert(it->key == tail_key);
        }
        for (auto it : std::next(cont_.begin())->forwards) {
            assert(it == cont_.end());
        }
        std::cerr << "UT_DEBUG: all assert in init_internally() success!\n";
#endif

        return;
    }
    /**
     * @brief   return a const_iterator points to the last element
     *          such that its hash_key <= target_hash_key
     */
    const_iterator find_helper(const hash_type& key) const {
#ifdef LIAM_UT_DEBUG_
        std::cerr << "Keys contained in the list: ";
        for (auto node : cont_) {
            std::cerr << node.key << ' ';
        }
        std::cerr << '\n';
        std::cerr << "Target key: " << key << '\n';
#endif
        const_iterator iter = begin();
        for (size_type i = 0; i != max_lv_; ++i) {
            size_type focus = max_lv_ - 1 - i;
            // invariant: iter->key <= key
            while (not compare()(key, iter->forwards[focus]->key)) {
#ifdef LIAM_UT_DEBUG_
                std::cerr << "i: " << i << " focus: " << focus << ". "
                          << "since iter->forwards[focus]->key[" << iter->forwards[focus]->key
                          << "] <= key[" << key << "], ";
#endif
                iter = iter->forwards[focus];
#ifdef LIAM_UT_DEBUG_
                std::cerr << "step forward iter to [" << iter->key << "]\n";
#endif
            }
            // result: iter->key <= key < iter->forwards[focus]->key
#ifdef LIAM_UT_DEBUG_
            std::cerr << "The following fact holds at level " << focus
                      << ": iter->key[" << iter->key << "] <= key["
                      << key << "] < iter->forwards[focus]->key[" << iter->forwards[focus]->key
                      <<"].\n";
#endif
        }
        return iter;
    }
    std::vector<iterator> find_predecessors(const hash_type& key, const size_type& lv) {
#ifdef LIAM_UT_DEBUG_
        std::cerr << "Keys contained in the list: ";
        for (auto node : cont_) {
            std::cerr << node.key << ' ';
        }
        std::cerr << '\n';
        std::cerr << "Target key: " << key << '\n';
#endif
        std::vector<iterator> res;
        res.resize(lv + 1);
        iterator iter = begin();
        for (size_type i = 0; i != max_lv_; ++i) {
            size_type focus = max_lv_ - 1 - i;
#ifdef LIAM_UT_DEBUG_
            std::cerr << "i: " << i << " focus: " << focus << ".\n";
#endif
            // invariant: iter->key < key
            while (compare()(iter->forwards[focus]->key, key)) {
#ifdef LIAM_UT_DEBUG_
                std::cerr << "since iter->forwards[focus]->key[" << iter->forwards[focus]->key
                          << "] < key[" << key << "], ";
#endif
                iter = iter->forwards[focus];
#ifdef LIAM_UT_DEBUG_
                std::cerr << "step forward iter to [" << iter->key << "]\n";
#endif
            }
            // result: iter->key < key <= iter->forwards[focus]->key
#ifdef LIAM_UT_DEBUG_
            std::cerr << "The following fact holds at level " << focus
                      << ": iter->key[" << iter->key << "] < key[" << key
                      << "] <= iter->forwards[focus]->key[" << iter->forwards[focus]->key
                      <<"].\n";
#endif
            if (focus < lv + 1) {
                res[focus] = iter;
#ifdef LIAM_UT_DEBUG_
                std::cerr << "predecessor at level [" << focus
                          << "] has been recorded, while level upper limit is " << lv <<".\n";
#endif
            }
        }
        return res;
    }

  public:
    size_type size() const {
        return cont_.size() - 2;
    }
    bool empty() const {
        return size() == 0;
    }
    iterator begin() {
        return cont_.begin();
    }
    const_iterator begin() const {
        return cont_.cbegin();
    }
    const_iterator cbegin() const {
        return cont_.cbegin();
    }
    iterator end() {
        return cont_.end();
    }
    const_iterator end() const {
        return cont_.cend();
    }
    const_iterator cend() const {
        return cont_.cend();
    }
    void grow(const size_type new_max_lv) {
        if (max_lv_ < new_max_lv) {
#ifdef LIAM_UT_DEBUG_
            std::cerr << "grow from [" << max_lv_ << "] to ["
                      << new_max_lv << "]!\n";
#endif
            max_lv_ = new_max_lv;

            iterator tail = std::prev(cont_.end());
            auto beg_tail = tail->forwards.end();
            tail->forwards.resize(max_lv_, cont_.end());

            iterator head = cont_.begin();
            auto beg_head = head->forwards.end();
            head->forwards.resize(max_lv_, tail);

            return;
        } else {
#ifdef LIAM_UT_DEBUG_
            std::cerr << "abandon growing!\n";
#endif
            return;
        }
    }
    void grow() {
        grow(Factor * max_lv_);
    }
    size_type capability() const {
        return std::pow(Factor, max_lv_);
    }

  public:
    const_iterator find(const value_type& target) const {
#ifdef LIAM_UT_DEBUG_
            std::cerr << "finding [" << target << "]!\n";
#endif
        const hash_type key = hasher()(target);
        const_iterator iter = find_helper(key);
        return (iter->key == key) ? iter : cont_.end();
    }
    void insert(const value_type& target) {
#ifdef LIAM_UT_DEBUG_
            std::cerr << "inserting [" << target << "]!\n";
#endif
        if (size() > static_cast<double>(Factor - 1) / Factor * capability()) {
#ifdef LIAM_UT_DEBUG_
            std::cerr << "size[" << size() << "], Factor[" << Factor << "], capability[" << capability() << "]!\n";
#endif
            grow();
        }
        const hash_type key = hasher()(target);
        const size_type lv  = rl_();
        std::vector<iterator> predecessors = find_predecessors(key, lv);
        if (predecessors[0]->forwards[0]->key == key) {  // key already in skiplist
#ifdef LIAM_UT_DEBUG_
            std::cerr << "key [" << key << "] already in the skiplist, insert directly!\n";
#endif
            predecessors[0]->forwards[0]->values.insert(target);
            return;
        } else {
#ifdef LIAM_UT_DEBUG_
            std::cerr << "key [" << key << "] not in the skiplist, insert a new node!\n";
#endif
            node_type node(key);
            node.forwards.resize(lv + 1);
            node.values.insert(target);
            iterator inserted = cont_.insert(predecessors[0]->forwards[0], std::move(node));
            for (size_type i = 0; i != lv + 1; ++i) {
                inserted->forwards[i]        = predecessors[i]->forwards[i];
                predecessors[i]->forwards[i] = inserted;
            }
#ifdef LIAM_UT_DEBUG_
            assert(inserted->forwards[0] == std::next(inserted));
#endif
            return;
        }
    }
    void erase(const value_type& target,
              const erase_policy policy = erase_policy::ALL) {
#ifdef LIAM_UT_DEBUG_
            std::cerr << "erasing [" << target << "]!\n";
#endif
        const hash_type key = hasher()(target);
        std::vector<iterator> predecessors = find_predecessors(key, max_lv_);
        if (predecessors[0]->forwards[0]->key == key) {  // hit
#ifdef LIAM_UT_DEBUG_
            std::cerr << "key [" << key << "] is in the skiplist!\n";
#endif
            iterator found = predecessors[0]->forwards[0];
            for (auto iter = found->values.begin(); iter != found->values.end(); ) {
                if (policy == erase_policy::ALL) {
                    if (*iter == target) {
                        iter = found->values.erase(iter);
                    } else {
                        ++iter;
                    }
                } else if (policy == erase_policy::SINGLE) {
                    if (*iter == target) {
                        found->values.erase(iter);
                        break;
                    }
                }
            }
#ifdef LIAM_UT_DEBUG_
            std::cerr << "target(s) removed!\n";
#endif
            if (found->values.empty()) {
                const size_type lvp1 = found->forwards.size();  // lv plus 1
                for (size_type i = 0; i != lvp1; ++i) {
                    predecessors[i]->forwards[i] = found->forwards[i];
                }
                cont_.erase(found);
#ifdef LIAM_UT_DEBUG_
            std::cerr << "empty node removed!\n";
#endif
                return;
            } else {
                return;
            }
        } else {
#ifdef LIAM_UT_DEBUG_
            std::cerr << "key [" << key << "] is not in the skiplist, do nothing!\n";
#endif
            return;
        }
    }
};

#endif  // SKIPLIST_SKIPLIST_TR_HPP_
