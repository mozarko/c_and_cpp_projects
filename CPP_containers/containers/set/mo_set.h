#ifndef mo_SET_H
#define mo_SET_H

#include "../binary_tree/mo_binary_tree.h"

namespace mo {

template <typename Key> class set : public binary_tree<Key, Key> {
public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename binary_tree<Key, Key>::iterator;
  using const_iterator = typename binary_tree<Key, Key>::const_iterator;
  using size_type = size_t;

  set();
  set(std::initializer_list<value_type> const &items);
  set(const set &s);
  set(set &&s) noexcept;
  ~set() = default;
  set &operator=(set &&s) noexcept;

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const value_type &value);
  void erase(iterator pos);
  void swap(set &other) noexcept;
  void merge(set &other);

  iterator find(const Key &key);
  bool contains(const Key &key);
};
}; // namespace mo

#include "mo_set.tpp"

#endif
