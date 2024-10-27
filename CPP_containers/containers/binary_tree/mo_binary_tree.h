#ifndef mo_BINARY_TREE_H
#define mo_BINARY_TREE_H

#include <iostream>
#include <limits>

namespace mo {
template <typename Key, typename Value> class binary_tree {

public:
  struct Node {
    Node *left_, *right_, *parent_;
    Key key_;
    Value value_;
    Node(Key key, Value value, Node *parent = nullptr);
    ~Node();
  };

  class Iterator {
  public:
    Node *ptr;
    Iterator();
    explicit Iterator(Node *_ptr);
    Iterator &operator++();
    Iterator operator++(int);
    Iterator operator--(int);
    Iterator &operator--();
    bool operator==(Iterator other) const;
    bool operator!=(Iterator other) const;
    Node *operator->() const;
  };

  using key_type = Key;
  using mapped_type = Value;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using iterator = Iterator;
  using const_iterator = const Iterator;

  binary_tree();
  binary_tree(std::initializer_list<value_type> const &items);
  binary_tree(const binary_tree &other);
  binary_tree(binary_tree &&other) noexcept;
  ~binary_tree();

  binary_tree &operator=(binary_tree &&other) noexcept;
  iterator begin() const;
  iterator end() const;
  size_type size();
  size_type max_size();
  bool empty();
  void clear();

protected:
  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const key_type &key, const mapped_type &obj);
  std::pair<iterator, bool> insert_or_assign(const key_type &key,
                                             const mapped_type &obj);
  iterator insert(const key_type &key);
  void erase(iterator pos);
  void swap(binary_tree &other) noexcept;
  void merge(binary_tree &other);
  bool contains(const key_type &key);
  size_type count(const key_type &key);
  iterator find(const key_type &key);

  std::pair<iterator, iterator> equal_range(const key_type &key);
  iterator lower_bound(const key_type &key);
  iterator upper_bound(const key_type &key);
  iterator root;
  iterator iter;
  iterator begin_i;
  iterator end_i;
  mapped_type &at(const key_type &key);
  mapped_type &operator[](const key_type &key);

private:
  size_type size_;
  Node *fake;
  void assign(const binary_tree &other);
  bool contains(Node *root, const key_type &key);
  void insert(Node *iter, Node *_node);
  Node *insert(Node *iter, const key_type &key, const mapped_type &value);
  iterator set_begin();
  iterator set_end();
  Node *find(Node *root, const key_type &key);
};
}; // namespace mo

#include "mo_binary_tree.tpp"

#endif // mo_BINARY_TREE_H