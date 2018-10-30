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

namespace skiplist_detail {
template <typename Key, typename Value>
struct InternalNode {
    const Key                                               key;
    std::multiset<Value>                                    values;
    using iterator = typename std::list<InternalNode>::iterator;
    std::vector<iterator> forwards;
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
};

#endif  // SKIPLIST_SKIPLIST_TR_HPP_

