#ifndef mo_SET_TPP
#define mo_SET_TPP

namespace mo {
template <typename Key> set<Key>::set() : binary_tree<Key, Key>() {}

template <typename Key>
set<Key>::set(std::initializer_list<value_type> const &items)
    : binary_tree<Key, Key>() {
  for (auto i = items.begin(); i != items.end(); ++i)
    binary_tree<Key, Key>::insert(*i, Key());
}

template <typename Key>
set<Key>::set(const set &s) : binary_tree<Key, Key>(s) {}

template <typename Key>
set<Key>::set(set &&s) noexcept : binary_tree<Key, Key>(std::move(s)) {}

template <typename Key> set<Key> &set<Key>::operator=(set &&s) noexcept {
  binary_tree<Key, Key>::operator=(std::move(s));
  return *this;
}

template <typename Key> typename set<Key>::iterator set<Key>::begin() {
  return binary_tree<Key, Key>::begin();
}

template <typename Key> typename set<Key>::iterator set<Key>::end() {
  return binary_tree<Key, Key>::end();
}

template <typename Key> bool set<Key>::empty() {
  return binary_tree<Key, Key>::empty();
}

template <typename Key> typename set<Key>::size_type set<Key>::size() {
  return binary_tree<Key, Key>::size();
}

template <typename Key> typename set<Key>::size_type set<Key>::max_size() {
  return std::numeric_limits<typename set<Key>::size_type>::max() /
         sizeof(typename set<Key>::value_type);
}

template <typename Key> void set<Key>::clear() {
  binary_tree<Key, Key>::clear();
}

template <typename Key>
std::pair<typename set<Key>::iterator, bool>
set<Key>::insert(const value_type &value) {
  return binary_tree<Key, Key>::insert(value, Key());
}

template <typename Key> void set<Key>::erase(iterator pos) {
  binary_tree<Key, Key>::erase(pos);
}

template <typename Key> void set<Key>::swap(set &other) noexcept {
  binary_tree<Key, Key>::swap(other);
}

template <typename Key> void set<Key>::merge(set &other) {
  binary_tree<Key, Key>::merge(other);
}

template <typename Key>
typename set<Key>::iterator set<Key>::find(const Key &key) {
  return binary_tree<Key, Key>::find(key);
}
template <typename Key> bool set<Key>::contains(const Key &key) {
  return binary_tree<Key, Key>::contains(key);
}

}; // namespace mo

#endif
