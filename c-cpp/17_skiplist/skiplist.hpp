/**
 * Created by Liam Huang (Liam0205) on 2018/10/29.
 */

#ifndef SKIPLIST_SKIPLIST_HPP_
#define SKIPLIST_SKIPLIST_HPP_

#include <list>
#include <iterator>
#include <memory>
#include <initializer_list>
#include <utility>

template <typename T,
          typename Allocator = std::allocator<T>>
class skiplist : public std::list<T, Allocator> {
  public:
    using container_type         = std::list<T, Allocator>;
    using value_type             = typename container_type::value_type;
    using allocator_type         = typename container_type::allocator_type;
    using size_type              = typename container_type::size_type;
    using difference_type        = typename container_type::difference_type;
    using reference              = typename container_type::reference;
    using const_reference        = typename container_type::const_reference;
    using pointer                = typename container_type::pointer;
    using const_pointer          = typename container_type::const_pointer;
    using iterator               = typename container_type::iterator;
    using const_iterator         = typename container_type::const_iterator;
    using reverse_iterator       = typename container_type::reverse_iterator;
    using const_reverse_iterator = typename container_type::const_reverse_iterator;

  private:
    template <typename T, typename Iter>
    struct IndexNode {
        IndexNode(const T& data_, Iter down_) : data(data_), down(down_) {}
        const T    data;
        const Iter down;
    };

  public:
    skiplist() : container_type() {}
    explicit skiplist(const allocator_type& alloc) : container_type(alloc) {}
    skiplist(       size_type count,
              const_reference value,
        const allocator_type& alloc = allocator_type()) :
        container_type(count, value, alloc) {}
    explicit skiplist(size_type count, const allocator_type& alloc = allocator_type()) :
        container_type(count, alloc) {}
    template<typename InputIt>
    skiplist(InputIt first, InputIt last, const allocator_type& alloc = allocator_type()) :
        container_type(first, last, alloc) {}
    skiplist(const skiplist& other);
    skiplist(const skiplist& other, const allocator_type& alloc);
    skiplist(skiplist&& other);
    skiplist(skiplist&& other, const allocator_type& alloc);
    skiplist(std::initializer_list<value_type> init,
                         const allocator_type& alloc = allocator_type()) :
        container_type(std::forward<std::initializer_list<value_type>>(init), alloc) {}
    ~skiplist();

  public:
    skiplist& operator=(const skiplist& other);
    skiplist& operator=(skiplist&& other);
};

#endif  // SKIPLIST_SKIPLIST_HPP_


