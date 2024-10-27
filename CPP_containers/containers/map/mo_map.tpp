#ifndef mo_MAP_TPP
#define mo_MAP_TPP

namespace mo {

template <typename Key, typename T>
map<Key, T>::map() : binary_tree<Key, T>() {}

template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const &items)
    : binary_tree<Key, T>(items) {}

template <typename Key, typename T>
map<Key, T>::map(const map &m) : binary_tree<Key, T>(m) {}

template <typename Key, typename T>
map<Key, T>::map(map &&m) noexcept : binary_tree<Key, T>(std::move(m)) {}

template <typename Key, typename T>
map<Key, T> &map<Key, T>::operator=(map &&m) noexcept {
  binary_tree<Key, T>::operator=(std::move(m));
  return *this;
}

template <typename Key, typename T> T &map<Key, T>::at(const Key &key) {
  return binary_tree<Key, T>::at(key);
}

template <typename Key, typename T> T &map<Key, T>::operator[](const Key &key) {
  return binary_tree<Key, T>::operator[](key);
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::begin() {
  return binary_tree<Key, T>::begin();
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::end() {
  return binary_tree<Key, T>::end();
}

template <typename Key, typename T> bool map<Key, T>::empty() {
  return binary_tree<Key, T>::empty();
}

template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::size() {
  return binary_tree<Key, T>::size();
}

template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::max_size() {
  return binary_tree<Key, T>::max_size();
}

template <typename Key, typename T> void map<Key, T>::clear() {
  binary_tree<Key, T>::clear();
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool>
map<Key, T>::insert(const value_type &value) {
  return binary_tree<Key, T>::insert(value);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool>
map<Key, T>::insert(const Key &key, const T &obj) {
  return binary_tree<Key, T>::insert(key, obj);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool>
map<Key, T>::insert_or_assign(const Key &key, const T &obj) {
  return binary_tree<Key, T>::insert_or_assign(key, obj);
}

template <typename Key, typename T> void map<Key, T>::erase(iterator pos) {
  binary_tree<Key, T>::erase(pos);
}

template <typename Key, typename T>
void map<Key, T>::swap(map &other) noexcept {
  binary_tree<Key, T>::swap(other);
}

template <typename Key, typename T> void map<Key, T>::merge(map &other) {
  binary_tree<Key, T>::merge(other);
}

template <typename Key, typename T> bool map<Key, T>::contains(const Key &key) {
  return binary_tree<Key, T>::contains(key);
}

}; // namespace mo

#endif
