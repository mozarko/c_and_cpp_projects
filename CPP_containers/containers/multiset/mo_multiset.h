#ifndef mo_MULTISET_H
#define mo_MULTISET_H

#include "../binary_tree/mo_binary_tree.h"

namespace mo {

template <typename Key> class multiset : public binary_tree<Key, Key> {

public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename binary_tree<Key, Key>::iterator;
  using const_iterator = typename binary_tree<Key, Key>::const_iterator;
  using size_type = size_t;

  multiset();
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &ms);
  multiset(multiset &&ms) noexcept;
  ~multiset() = default;
  multiset &operator=(multiset &&ms) noexcept;

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  iterator insert(const value_type &value);
  void erase(iterator pos);
  void swap(multiset &other) noexcept;
  void merge(multiset &other);

  size_type count(const Key &key);
  iterator find(const Key &key);
  bool contains(const Key &key);
  std::pair<iterator, iterator> equal_range(const Key &key);
  iterator lower_bound(const Key &key);
  iterator upper_bound(const Key &key);
};

}; // namespace mo

#include "mo_multiset.tpp"

#endif