#ifndef mo_MAP_H
#define mo_MAP_H

#include "../binary_tree/mo_binary_tree.h"

namespace mo {
template <typename Key, typename T> class map : public binary_tree<Key, T> {
public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename binary_tree<Key, T>::iterator;
  using const_iterator = typename binary_tree<Key, T>::const_iterator;
  using size_type = size_t;

  map();
  map(std::initializer_list<value_type> const &items);
  map(const map &m);
  map(map &&m) noexcept;
  ~map() = default;
  map &operator=(map &&m) noexcept;

  T &at(const Key &key);
  T &operator[](const Key &key);

  iterator begin();
  iterator end();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const Key &key, const T &obj);
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);
  void erase(iterator pos);
  void swap(map &other) noexcept;
  void merge(map &other);

  bool contains(const Key &key);
};

}; // namespace mo

#include "mo_map.tpp"

#endif
