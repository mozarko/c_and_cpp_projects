#ifndef mo_AVL_TREE_TPP
#define mo_AVL_TREE_TPP

namespace mo {

template <typename Key, typename Value>
avl_tree<Key, Value>::avl_tree() : root_(nullptr) {}

template <typename Key, typename Value>
avl_tree<Key, Value>::avl_tree(const avl_tree &other) {
  root_ = CopyTree(other.root_, nullptr);
}

template <typename Key, typename Value>
avl_tree<Key, Value>::avl_tree(avl_tree &&other) noexcept {
  root_ = other.root_;
  other.root_ = nullptr;
}

template <typename Key, typename Value> avl_tree<Key, Value>::~avl_tree() {
  clear();
}

template <typename Key, typename Value>
avl_tree<Key, Value> &avl_tree<Key, Value>::operator=(const avl_tree &other) {
  if (this != &other) {
    avl_tree temp(other);
    FreeNode(root_);
    *this = std::move(temp);
  }
  return *this;
}

template <typename Key, typename Value>
avl_tree<Key, Value> &
avl_tree<Key, Value>::operator=(avl_tree &&other) noexcept {
  if (this != &other) {
    FreeNode(root_);
    root_ = other.root_;
    other.root_ = nullptr;
  }
  return *this;
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::iterator avl_tree<Key, Value>::begin() {
  return avl_tree::Iterator(FindMin(root_));
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::iterator avl_tree<Key, Value>::end() {
  if (root_ == nullptr)
    return begin();
  Node *node = FindMax(root_);
  Iterator end(nullptr, node);
  return end;
}

template <typename Key, typename Value> bool avl_tree<Key, Value>::empty() {
  return root_ == nullptr;
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::size_type avl_tree<Key, Value>::size() {
  return RecursiveSize(root_);
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::size_type avl_tree<Key, Value>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(Node);
}

template <typename Key, typename Value> void avl_tree<Key, Value>::clear() {
  if (root_ != nullptr)
    FreeNode(root_);
  root_ = nullptr;
}

template <typename Key, typename Value>
std::pair<typename avl_tree<Key, Value>::iterator, bool>
avl_tree<Key, Value>::insert(const Key &key) {
  std::pair<Iterator, bool> return_value;
  if (root_ == nullptr) {
    root_ = new Node(key, key);
    return_value.first = Iterator(root_);
    return_value.second = true;
  } else {
    bool inserted = RecursiveInsert(root_, key, key);
    return_value.first = Find(key);
    return_value.second = inserted;
  }
  return return_value;
}

template <typename Key, typename Value>
void avl_tree<Key, Value>::erase(iterator pos) {
  if (root_ == nullptr || pos.node_ == nullptr)
    return;
  root_ = RecursiveErase(root_, *pos);
}

template <typename Key, typename Value>
void avl_tree<Key, Value>::swap(avl_tree &other) {
  std::swap(root_, other.root_);
}

template <typename Key, typename Value>
void avl_tree<Key, Value>::merge(avl_tree &other) {
  avl_tree const_tree(other);
  Iterator const_it = const_tree.begin();
  while (const_it != const_tree.end()) {
    std::pair<Iterator, bool> pr = insert(*const_it);
    if (pr.second)
      other.erase(pr.first);
    ++const_it;
  }
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::iterator
avl_tree<Key, Value>::Find(const Key &key) {
  Node *node = RecursiveFind(root_, key);
  return Iterator(node);
}

template <typename Key, typename Value>
bool avl_tree<Key, Value>::contains(const Key &key) {
  Node *node = RecursiveFind(root_, key);
  return !(node == nullptr);
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::Node *
avl_tree<Key, Value>::Iterator::MoveForward(Node *node) {
  if (node->right_ != nullptr)
    return FindMin(node->right_);
  Node *parent = node->parent_;
  while (parent != nullptr && node == parent->right_) {
    node = parent;
    parent = parent->parent_;
  }
  return parent;
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::Node *
avl_tree<Key, Value>::Iterator::MoveBackward(Node *node) {
  if (node->left_ != nullptr)
    return FindMax(node->left_);
  Node *parent = node->parent_;
  while (parent != nullptr && node == parent->left_) {
    node = parent;
    parent = parent->parent_;
  }
  return parent;
}

template <typename Key, typename Value>
avl_tree<Key, Value>::Iterator::Iterator()
    : node_(nullptr), past_node_(nullptr) {}

template <typename Key, typename Value>
avl_tree<Key, Value>::Iterator::Iterator(Node *node, Node *past_node)
    : node_(node), past_node_(past_node) {}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::Iterator &
avl_tree<Key, Value>::Iterator::operator++() {
  Node *tmp;
  if (node_ != nullptr)
    tmp = FindMax(node_);
  node_ = MoveForward(node_);
  if (node_ == nullptr)
    past_node_ = tmp;
  return *this;
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::Iterator
avl_tree<Key, Value>::Iterator::operator++(int) {
  Iterator tmp = *this;
  operator++();
  return tmp;
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::Iterator &
avl_tree<Key, Value>::Iterator::operator--() {
  if (node_ == nullptr && past_node_ != nullptr) {
    *this = past_node_;
    return *this;
  }
  node_ = MoveBackward(node_);
  return *this;
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::Iterator
avl_tree<Key, Value>::Iterator::operator--(int) {
  Iterator tmp = *this;
  operator--();
  return tmp;
}

template <typename Key, typename Value>
bool avl_tree<Key, Value>::Iterator::operator==(const Iterator &other) const {
  return node_ == other.node_;
}

template <typename Key, typename Value>
bool avl_tree<Key, Value>::Iterator::operator!=(const Iterator &other) const {
  return node_ != other.node_;
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::reference
avl_tree<Key, Value>::Iterator::operator*() {
  if (node_ == nullptr) {
    static Value value;
    return value;
  }
  return node_->key_;
}

template <typename Key, typename Value>
avl_tree<Key, Value>::Node::Node(Key key, value_type value)
    : key_(key), value_(value) {}

template <typename Key, typename Value>
avl_tree<Key, Value>::Node::Node(Key key, value_type value, Node *parent)
    : key_(key), value_(value), parent_(parent) {}

template <typename Key, typename Value>
void avl_tree<Key, Value>::FreeNode(Node *node) {
  if (node == nullptr)
    return;
  FreeNode(node->left_);
  FreeNode(node->right_);
  delete node;
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::Node *
avl_tree<Key, Value>::CopyTree(Node *node, Node *parent) {
  if (node == nullptr)
    return nullptr;
  Node *new_node = new Node(node->key_, node->value_, parent);
  new_node->left_ = CopyTree(node->left_, new_node);
  new_node->right_ = CopyTree(node->right_, new_node);
  return new_node;
}

template <typename Key, typename Value>
void avl_tree<Key, Value>::SwapNodes(Node *node1, Node *node2) {
  std::swap(node1->key_, node2->key_);
  std::swap(node1->value_, node2->value_);
}

template <typename Key, typename Value>
void avl_tree<Key, Value>::RightRotate(Node *node) {
  Node *new_left = node->left_->left_;
  Node *new_right_right = node->right_->right_;
  Node *new_right_left = node->left_->right_;

  swap(node, node->left_);
  node->right_ = node->left_;

  node->left_ = new_left;
  if (node->left_)
    node->left_->parent_ = node;

  node->right_->left_ = new_right_left;
  if (node->right_->left_)
    node->right_->left_->parent_ = node->right_;

  node->right_->right_ = new_right_right;
  if (node->right_->right_)
    node->right_->right_->parent_ = node->right_;

  SetHeight(node->right_);
  SetHeight(node);
}

template <typename Key, typename Value>
void avl_tree<Key, Value>::LeftRotate(Node *node) {
  Node *new_right = node->right_->right_;
  Node *new_left_left = node->left_;
  Node *new_left_right = node->right_->left_;

  swap(node, node->right_);
  node->left_ = node->right_;

  node->right_ = new_right;
  if (node->right_)
    node->right_->parent_ = node;

  node->left_->right_ = new_left_right;
  if (node->left_->right_)
    node->left_->right_->parent_ = node->left_;

  node->left_->left_ = new_left_left;
  if (node->left_->left_)
    node->left_->left_->parent_ = node->left_;

  SetHeight(node->left_);
  SetHeight(node);
}

template <typename Key, typename Value>
void avl_tree<Key, Value>::Balance(Node *node) {
  int balance = GetBalance(node);
  if (balance == -2) {
    if (GetBalance(node->left_) == 1)
      LeftRotate(node->left_);
    RightRotate(node);
  } else if (balance == 2) {
    if (GetBalance(node->left_) == -1)
      RightRotate(node->right_);
    LeftRotate(node);
  }
}

template <typename Key, typename Value>
int avl_tree<Key, Value>::GetHeight(Node *node) {
  return node == nullptr ? -1 : node->height_;
}

template <typename Key, typename Value>
int avl_tree<Key, Value>::GetBalance(Node *node) {
  return node == nullptr ? 0 : GetHeight(node->right_) - GetHeight(node->left_);
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::Node *avl_tree<Key, Value>::FindMin(Node *node) {
  if (node == nullptr)
    return nullptr;
  if (node->left_ == nullptr)
    return node;
  return FindMin(node->left_);
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::Node *avl_tree<Key, Value>::FindMax(Node *node) {
  if (node == nullptr)
    return nullptr;
  if (node->right_ == nullptr)
    return node;
  return FindMax(node->right_);
}

template <typename Key, typename Value>
bool avl_tree<Key, Value>::RecursiveInsert(Node *node, const Key &key,
                                           Value value) {
  bool inserted = false;

  if (key < node->key_) {
    if (node->left_ == nullptr) {
      node->left_ = new Node(key, value, node);
      inserted = true;
    } else
      inserted = RecursiveInsert(node->left_, key, value);
  } else if (key > node->key_) {
    if (node->right_ == nullptr) {
      node->right_ = new Node(key, value, node);
      inserted = true;
    } else
      inserted = RecursiveInsert(node->right_, key, value);
  } else if (key == node->key_)
    return inserted;
  SetHeight(node);
  Balance(node);
  return inserted;
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::Node *
avl_tree<Key, Value>::RecursiveDelete(Node *node, Key key) {
  if (node == nullptr)
    return nullptr;
  if (key < node->key_)
    node->left_ = RecursiveDelete(node->left_, key);
  else if (key > node->key_)
    node->right_ = RecursiveDelete(node->right_, key);
  else {
    if (node->left_ == nullptr && node->right_ == nullptr) {
      Node *node_right = node->right_;
      Node *node_left = node->left_;
      Node *node_parent = node->parent_;
      delete node;
      if (node_left == nullptr)
        node = node_right;
      else
        node = node_left;
      if (node != nullptr)
        node->parent_ = node_parent;
      else {
        Node *min_in_right = GetMin(node->right_);
        node->key_ = min_in_right->key_;
        node->value_ = min_in_right->value_;
        node->right_ = RecursiveDelete(node->right_, min_in_right->key_);
      }
    }
  }
  if (node != nullptr) {
    SetHeight(node);
    Balance(node);
  }
  return node;
}

template <typename Key, typename Value>
size_t avl_tree<Key, Value>::RecursiveSize(Node *node) {
  if (node == nullptr)
    return 0;
  size_t left_size = RecursiveSize(node->left_);
  size_t right_size = RecursiveSize(node->right_);
  return 1 + left_size + right_size;
}

template <typename Key, typename Value>
typename avl_tree<Key, Value>::Node *
avl_tree<Key, Value>::RecursiveFind(Node *node, const Key &key) {
  if (node == nullptr || node->key_ == key)
    return node;
  if (key > node->key_) {
    return RecursiveFind(node->right_, key);
  } else
    return RecursiveFind(node->left_, key);
}

}; // namespace mo

#endif
