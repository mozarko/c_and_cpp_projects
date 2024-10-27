#ifndef mo_MULTISET_TPP
#define mo_MULTISET_TPP

namespace mo {

template <typename Key> multiset<Key>::multiset() : binary_tree<Key, Key>() {}

template <typename Key>
multiset<Key>::multiset(std::initializer_list<value_type> const &items)
    : binary_tree<Key, Key>() {
  for (auto i = items.begin(); i != items.end(); ++i)
    multiset<Key>::insert(*i);
}

template <typename Key>
multiset<Key>::multiset(const multiset &ms) : binary_tree<Key, Key>(ms) {}

template <typename Key>
multiset<Key>::multiset(multiset &&ms) noexcept
    : binary_tree<Key, Key>(std::move(ms)) {}

template <typename Key>
multiset<Key> &multiset<Key>::operator=(multiset &&ms) noexcept {
  binary_tree<Key, Key>::operator=(std::move(ms));
  return *this;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::begin() {
  return binary_tree<Key, Key>::begin();
}

template <typename Key> typename multiset<Key>::iterator multiset<Key>::end() {
  return binary_tree<Key, Key>::end();
}

template <typename Key> bool multiset<Key>::empty() {
  return binary_tree<Key, Key>::empty();
}

template <typename Key>
typename multiset<Key>::size_type multiset<Key>::size() {
  return binary_tree<Key, Key>::size();
}

template <typename Key>
typename multiset<Key>::size_type multiset<Key>::max_size() {
  return std::numeric_limits<multiset<Key>::size_type>::max() /
         sizeof(multiset<Key>::value_type);
}

template <typename Key> void multiset<Key>::clear() {
  binary_tree<Key, Key>::clear();
}

template <typename Key>
typename multiset<Key>::iterator
multiset<Key>::insert(const value_type &value) {
  return binary_tree<Key, Key>::insert(value);
}

template <typename Key> void multiset<Key>::erase(iterator pos) {
  binary_tree<Key, Key>::erase(pos);
}

template <typename Key> void multiset<Key>::swap(multiset &other) noexcept {
  binary_tree<Key, Key>::swap(other);
}

template <typename Key> void multiset<Key>::merge(multiset &other) {
  binary_tree<Key, Key>::merge(other);
}

template <typename Key>
typename multiset<Key>::size_type multiset<Key>::count(const Key &key) {
  return binary_tree<Key, Key>::count(key);
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::find(const Key &key) {
  return binary_tree<Key, Key>::find(key);
}

template <typename Key> bool multiset<Key>::contains(const Key &key) {
  return binary_tree<Key, Key>::contains(key);
}

template <typename Key>
std::pair<typename multiset<Key>::iterator, typename multiset<Key>::iterator>
multiset<Key>::equal_range(const Key &key) {
  return binary_tree<Key, Key>::equal_range(key);
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(const Key &key) {
  return binary_tree<Key, Key>::lower_bound(key);
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(const Key &key) {
  return binary_tree<Key, Key>::upper_bound(key);
}

}; // namespace mo

#endif