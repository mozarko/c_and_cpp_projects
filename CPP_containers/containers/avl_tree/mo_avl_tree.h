#ifndef mo_AVL_TREE_H
#define mo_AVL_TREE_H

namespace mo {
template <typename Key, typename Value> class avl_tree {

protected:
  struct Node;

public:
  class Iterator;
  class ConstIterator;

  using key_type = Key;
  using value_type = Value;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using iterator = Iterator;
  using const_iterator = ConstIterator;

  class Iterator {

  public:
    Iterator();
    Iterator(Node *node, Node *past_node = nullptr);
    Iterator &operator++();
    Iterator operator++(int);
    Iterator &operator--();
    Iterator operator--(int);
    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;
    reference operator*();
    friend class avl_tree<Key, Value>;

  protected:
    Node *node_;
    Node *past_node_;
    Node *MoveForward(Node *node);
    Node *MoveBackward(Node *node);
  }; // class Iterator

  class ConstIterator : public Iterator {
  public:
    ConstIterator() : Iterator(){};
    const_reference operator*() const { return Iterator::operator*(); };
  }; // class ConstIterator

  avl_tree();
  avl_tree(const avl_tree &other);
  avl_tree(avl_tree &&other) noexcept;
  ~avl_tree();
  avl_tree &operator=(const avl_tree &other);
  avl_tree &operator=(avl_tree &&other) noexcept;
  iterator begin();
  iterator end();
  bool empty();
  size_type size();
  size_type max_size();
  void clear();
  std::pair<iterator, bool> insert(const Key &key);
  void erase(iterator pos);
  void swap(avl_tree &other);
  void merge(avl_tree &other);
  bool contains(const Key &key);

protected:
  iterator Find(const Key &key);

  struct Node {
    Node(Key key, value_type value);
    Node(Key key, value_type value, Node *parent);
    Key key_;
    value_type value_;
    Node *left_ = nullptr;
    Node *right_ = nullptr;
    Node *parent_ = nullptr;
    int height_ = 0;
    friend class avl_tree<Key, Value>;
  }; // struct Node
  Node *root_;

  void FreeNode(Node *node);
  Node *CopyTree(Node *node, Node *parent);
  void SwapNodes(Node *node1, Node *node2);
  void RightRotate(Node *node);
  void LeftRotate(Node *node);
  void Balance(Node *node);
  int GetHeight(Node *node);
  int GetBalance(Node *node);
  void SetHeight(Node *node);
  static Node *FindMin(Node *node);
  static Node *FindMax(Node *node);
  bool RecursiveInsert(Node *node, const Key &key, Value value);
  Node *RecursiveDelete(Node *node, Key key);
  size_t RecursiveSize(Node *node);
  Node *RecursiveFind(Node *node, const Key &key);

}; // class avl_tree
}; // namespace mo

#include "mo_avl_tree.tpp"

#endif
