/**
 * Created by Liam Huang (Liam0205) on 2018/08/14.
 * This is an old test file for hash_map, created by Liam.
 * Just for showing the inner logic for hash_map class template.
 * Original posted on:
 *   https://github.com/Liam0205/leetcode/tree/master/met/hash_map.cc
 */

#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <memory>

template <typename Key, typename T, typename Hash = std::hash<Key>>
class hash_map {
  public:
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const key_type, mapped_type>;
    using size_type = size_t;
    using hasher = std::hash<Key>;

  private:  // helper
    using wrapper = std::shared_ptr<value_type>;

  public:  // constructor
    hash_map() {
        container_.resize(primes_[size_level_]);
    }

  public:  // capacity
    bool empty() const { return empty_; }
    size_type size() const { return size_; }
    size_type max_size() const { return primes_[size_level_]; }

  public:  // find and modify
    mapped_type& operator[](const key_type& key) {
        auto hashed = find_hash(key);
        if (not(container_[hashed]) and construct_new_on_position(hashed, key) and
                load_factor() > max_load_factor()) {
            expand();
        }
        return container_[hashed]->second;
    }

  public:  // hash policy
    double load_factor() const { return static_cast<double>(size()) / max_size(); }
    double max_load_factor() const { return max_load_factor_; }
    void expand() const {
        ++size_level_;
        std::vector<wrapper> temp;
        temp.resize(primes_[size_level_]);
        for (auto w : container_) {
            if (nullptr != w) {
                auto hashed = find_hash(w->first);
                temp[hashed] = w;
            }
        }
        container_ = std::move(temp);
    }

  private:  // helper functions
    size_type find_hash(const key_type& key) const {
        const size_t csz = container_.size();
        size_t count = 0;
        size_t hashed = hasher_(key) % csz;
        while (nullptr != container_[hashed] and container_[hashed]->first != key) {
            hashed = (hashed + ++count) % csz;
        }
        return hashed;
    }
    bool construct_new_on_position(const size_type pos, const key_type& key) {
        empty_ = false;
        ++size_;
        container_[pos] = std::make_shared<value_type>(std::make_pair(key, mapped_type()));
        return true;
    }

  private:
    const hasher hasher_ = hasher();
    mutable size_t size_level_ = 0;
    mutable std::vector<wrapper> container_;
    static const size_t primes_[];
    bool empty_ = true;
    size_type size_ = 0;
    double max_load_factor_ = 0.75;
};
template <typename Key, typename T, typename Hash>
const size_t hash_map<Key, T, Hash>::primes_[] = {7, 17, 29, 53, 101, 211, 401, 809, 1601, 3203};  // ...

int main() {
    hash_map<int, int> test;
    test[1];
    test[2] = 2;
    std::cout << test[1] << ' ' << test[2] << std::endl;
    return 0;
}
