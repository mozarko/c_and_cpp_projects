#ifndef mo_BINARY_TREE_TPP
#define mo_BINARY_TREE_TPP

namespace mo {

template <typename Key, typename Value>
binary_tree<Key, Value>::Node::Node(Key key, Value value, Node *parent)
    : left_(nullptr), right_(nullptr), parent_(parent), key_(key),
      value_(value) {}

template <typename Key, typename Value> binary_tree<Key, Value>::Node::~Node() {
  if (right_)
    delete right_;
  if (left_)
    delete left_;
}

template <typename Key, typename Value>
binary_tree<Key, Value>::Iterator::Iterator() : ptr(nullptr) {}

template <typename Key, typename Value>
binary_tree<Key, Value>::Iterator::Iterator(Node *_ptr) : ptr(_ptr) {}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::Iterator &
binary_tree<Key, Value>::Iterator::operator++() {
  if (ptr != nullptr) {
    if (ptr->right_ != nullptr) {
      ptr = ptr->right_;
      if (ptr->left_ != nullptr)
        while (ptr->left_ != nullptr)
          ptr = ptr->left_;
    } else if (ptr->parent_ != nullptr) {
      iterator tmp(ptr->parent_);
      while ((tmp->parent_ != nullptr && ptr->key_ >= tmp->key_) ||
             ptr->key_ >= tmp->key_)
        tmp.ptr = tmp->parent_;
      ptr = tmp.ptr;
    }
  }
  return *this;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::Iterator
binary_tree<Key, Value>::Iterator::operator++(int) {
  Iterator tmp(ptr);
  ++(*this);
  return tmp;
}
template <typename Key, typename Value>
typename binary_tree<Key, Value>::Iterator &
binary_tree<Key, Value>::Iterator::operator--() {
  if (ptr != nullptr) {
    if (ptr->left_ != nullptr) {
      ptr = ptr->left_;
      if (ptr->right_ != nullptr)
        while (ptr->right_ != nullptr)
          ptr = ptr->right_;
    } else if (ptr->parent_ != nullptr) {
      iterator tmp(ptr->parent_);
      while ((tmp->parent_ != nullptr && ptr->key_ < tmp->key_) ||
             ptr->key_ < tmp->key_)
        tmp.ptr = tmp->parent_;
      ptr = tmp.ptr;
    }
  }
  return *this;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::Iterator
binary_tree<Key, Value>::Iterator::operator--(int) {
  Iterator tmp(ptr);
  --(*this);
  return tmp;
}

template <typename Key, typename Value>
bool binary_tree<Key, Value>::Iterator::operator==(Iterator other) const {
  return other.ptr == this->ptr;
}

template <typename Key, typename Value>
bool binary_tree<Key, Value>::Iterator::operator!=(Iterator other) const {
  return other.ptr != this->ptr;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::Node *
binary_tree<Key, Value>::Iterator::operator->() const {
  return ptr;
}

template <typename Key, typename Value>
binary_tree<Key, Value>::binary_tree() : size_(0), fake(nullptr) {}

template <typename Key, typename Value>
binary_tree<Key, Value>::binary_tree(
    std::initializer_list<value_type> const &items)
    : size_(0), fake(nullptr) {
  for (auto i = items.begin(); i != items.end(); ++i)
    insert(i->first, i->second);
}

template <typename Key, typename Value>
binary_tree<Key, Value>::binary_tree(const binary_tree &other)
    : size_(0), fake(nullptr) {
  assign(other);
}

template <typename Key, typename Value>
binary_tree<Key, Value>::binary_tree(binary_tree &&other) noexcept
    : size_(0), fake(nullptr) {
  assign(other);
  other.clear();
}

template <typename Key, typename Value>
binary_tree<Key, Value>::~binary_tree() {
  if (root.ptr)
    delete root.ptr;
}

template <typename Key, typename Value>
binary_tree<Key, Value> &
binary_tree<Key, Value>::operator=(binary_tree &&other) noexcept {
  assign(other);
  other.clear();
  return *this;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::iterator
binary_tree<Key, Value>::begin() const {
  return begin_i;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::iterator
binary_tree<Key, Value>::end() const {
  return end_i;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::size_type binary_tree<Key, Value>::size() {
  return binary_tree<Key, Value>::size_;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::size_type
binary_tree<Key, Value>::max_size() {
  return std::numeric_limits<
             typename binary_tree<Key, Value>::size_type>::max() /
         sizeof(typename binary_tree<Key, Value>::value_type);
}

template <typename Key, typename Value> bool binary_tree<Key, Value>::empty() {
  return size_ == 0;
}

template <typename Key, typename Value> void binary_tree<Key, Value>::clear() {
  if (root.ptr)
    delete root.ptr;
  root.ptr = nullptr;
  fake = nullptr;
  iter.ptr = nullptr;
  begin_i.ptr = nullptr;
  end_i.ptr = nullptr;
  size_ = 0;
}

template <typename Key, typename Value>
std::pair<typename binary_tree<Key, Value>::iterator, bool>
binary_tree<Key, Value>::insert(const value_type &value) {
  return insert(value.first, value.second);
}

template <typename Key, typename Value>
std::pair<typename binary_tree<Key, Value>::iterator, bool>
binary_tree<Key, Value>::insert(const key_type &key, const mapped_type &obj) {
  bool result = false;
  std::pair<iterator, bool> pair;
  if (!contains(key)) {
    pair = insert_or_assign(key, obj);
    result = pair.second;
  }
  return std::pair<iterator, bool>(pair.first, result);
}

template <typename Key, typename Value>
std::pair<typename binary_tree<Key, Value>::iterator, bool>
binary_tree<Key, Value>::insert_or_assign(const key_type &key,
                                          const mapped_type &obj) {
  bool result = true;
  if (fake != nullptr && end_i.ptr != nullptr) {
    --end_i;
    end_i->right_ = nullptr;
    delete fake;
  }
  if (!empty())
    iter.ptr = root.ptr;
  iter.ptr = insert(iter.ptr, key, obj);
  size_++;
  set_begin();
  set_end();
  return std::pair<iterator, bool>(iter, result);
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::iterator
binary_tree<Key, Value>::insert(const key_type &key) {
  if (fake != nullptr && end_i.ptr != nullptr) {
    --end_i;
    end_i->right_ = nullptr;
    delete fake;
  }
  if (!empty())
    iter.ptr = root.ptr;
  insert(iter.ptr, new Node(key, Key()));
  size_++;
  set_begin();
  set_end();
  return iter;
}

template <typename Key, typename Value>
void binary_tree<Key, Value>::erase(iterator pos) {
  Node *tmp = nullptr;
  for (auto i = begin(); i != end(); ++i) {
    if (pos == i) {
      tmp = i.ptr;
    }
  }
  if (tmp != nullptr) {
    if (fake != nullptr) {
      --end_i;
      end_i->right_ = nullptr;
      delete fake;
    }
    if (tmp->parent_ == nullptr) {
      root.ptr = (tmp->right_ != nullptr) ? tmp->right_ : tmp->left_;
    } else {
      iter.ptr = tmp->parent_;
      if (iter->right_ == tmp)
        iter->right_ = nullptr;
      else
        iter->left_ = nullptr;
    }
    if (tmp->right_ != nullptr && root.ptr != tmp->right_) {
      iter.ptr = root.ptr;
      insert(iter.ptr, tmp->right_);
    }
    if (tmp->left_ != nullptr && root.ptr != tmp->left_) {
      iter.ptr = root.ptr;
      insert(iter.ptr, tmp->left_);
    }
    size_--;
    tmp->right_ = nullptr;
    tmp->left_ = nullptr;
    delete tmp;
    set_begin();
    set_end();
  }
}

template <typename Key, typename Value>
void binary_tree<Key, Value>::swap(binary_tree &other) noexcept {
  binary_tree tmp(other);
  other.clear();
  other.assign(*this);
  binary_tree<Key, Value>::clear();
  assign(tmp);
  tmp.clear();
}

template <typename Key, typename Value>
void binary_tree<Key, Value>::merge(binary_tree &other) {
  assign(other);
}

template <typename Key, typename Value>
bool binary_tree<Key, Value>::contains(const key_type &key) {
  return contains(root.ptr, key);
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::size_type
binary_tree<Key, Value>::count(const key_type &key) {
  size_type _count = 0;
  for (auto i = begin(); i != end(); ++i)
    if (key == i->key_)
      _count++;
  return _count;
}
template <typename Key, typename Value>
typename binary_tree<Key, Value>::iterator
binary_tree<Key, Value>::find(const key_type &key) {
  iter.ptr = root.ptr;
  iter.ptr = find(iter.ptr, key);
  return iter;
}

template <typename Key, typename Value>
std::pair<typename binary_tree<Key, Value>::iterator,
          typename binary_tree<Key, Value>::iterator>
binary_tree<Key, Value>::equal_range(const key_type &key) {
  return std::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::iterator
binary_tree<Key, Value>::lower_bound(const key_type &key) {
  iter.ptr = nullptr;
  for (auto i = begin(); i != end(); ++i)
    if (key == i->key_) {
      iter.ptr = i.ptr;
      break;
    }
  return iter;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::iterator
binary_tree<Key, Value>::upper_bound(const key_type &key) {
  iter.ptr = nullptr;
  auto i = end();
  while (i != begin()) {
    --i;
    if (key == i->key_) {
      ++i;
      iter.ptr = i.ptr;
      break;
    }
  }
  return iter;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::mapped_type &
binary_tree<Key, Value>::at(const key_type &key) {
  iter.ptr = root.ptr;
  Node *result = find(iter.ptr, key);
  if (result == nullptr)
    throw std::out_of_range("");
  return result->value_;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::mapped_type &
binary_tree<Key, Value>::operator[](const key_type &key) {
  iter.ptr = root.ptr;
  Node *result = find(iter.ptr, key);
  if (result == nullptr)
    result = insert_or_assign(key, Value()).first.ptr;
  return result->value_;
}

template <typename Key, typename Value>
void binary_tree<Key, Value>::assign(const binary_tree &other) {
  for (auto i = other.begin(); i != other.end(); ++i)
    insert(i->key_, i->value_);
}

template <typename Key, typename Value>
bool binary_tree<Key, Value>::contains(Node *root, const key_type &key) {
  bool result = false;
  if (root != nullptr) {
    if (root->key_ == key)
      result = true;
    else if (root->key_ < key) {
      if (root->right_ != nullptr)
        result = contains(root->right_, key);
    } else if (root->left_ != nullptr)
      result = contains(root->left_, key);
  }
  return result;
}

template <typename Key, typename Value>
void binary_tree<Key, Value>::insert(Node *iter, Node *_node) {
  if (root.ptr == nullptr) {
    root.ptr = _node;
    iter = _node;
  } else if (_node->key_ >= iter->key_) {
    if (iter->right_ == nullptr) {
      _node->parent_ = iter;
      iter->right_ = _node;
    } else
      insert(iter->right_, _node);
  } else {
    if (iter->left_ == nullptr) {
      _node->parent_ = iter;
      iter->left_ = _node;
    } else
      insert(iter->left_, _node);
  }
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::Node *
binary_tree<Key, Value>::insert(Node *iter, const key_type &key,
                                const mapped_type &value) {
  if (root.ptr == nullptr) {
    root.ptr = new Node(key, value, nullptr);
    iter = root.ptr;
  } else {
    if (iter->key_ == key) {
      iter->value_ = value;
    } else if (key > iter->key_) {
      if (iter->right_ == nullptr) {
        iter->right_ = new Node(key, value, iter);
        iter = iter->right_;
      } else
        iter = insert(iter->right_, key, value);
    } else {
      if (iter->left_ == nullptr) {
        iter->left_ = new Node(key, value, iter);
        iter = iter->left_;
      } else
        iter = insert(iter->left_, key, value);
    }
  }
  return iter;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::iterator
binary_tree<Key, Value>::set_begin() {
  begin_i.ptr = root.ptr;
  if (root.ptr != nullptr)
    while (begin_i->left_ != nullptr)
      begin_i.ptr = begin_i->left_;
  return begin_i;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::iterator binary_tree<Key, Value>::set_end() {
  end_i.ptr = root.ptr;
  if (root.ptr != nullptr) {
    while (end_i->right_ != nullptr)
      end_i.ptr = end_i->right_;
    fake = new Node(end_i->key_, end_i->value_);
    fake->parent_ = end_i.ptr;
    end_i->right_ = fake;
    end_i.ptr = fake;
  }
  return end_i;
}

template <typename Key, typename Value>
typename binary_tree<Key, Value>::Node *
binary_tree<Key, Value>::find(Node *root, const key_type &key) {
  if (root != nullptr && root->key_ != key) {
    if (root->key_ < key) {
      if (root->right_ != nullptr)
        root = find(root->right_, key);
      else
        root = nullptr;
    } else {
      if (root->left_ != nullptr)
        root = find(root->left_, key);
      else
        root = nullptr;
    }
  }
  return root;
}

}; // namespace mo

#endif