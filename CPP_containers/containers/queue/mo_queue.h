#pragma once

namespace mo {
template <typename T>
class queue {
 public:
  // member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // member functions
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();
  queue &operator=(queue &&q);
  queue &operator=(const queue &q);

  // Element access
  const_reference front();
  const_reference back();

  // Capacity
  bool empty();
  size_type size();

  // Modifiers
  void push(const_reference value);
  void pop();
  void clear();
  void swap(queue &other);

  // insert_many
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  struct Node {
    value_type data;
    Node *next;
    explicit Node(const_reference value) : data(value), next(nullptr){};
  };

  Node *front_;
  Node *back_;
  size_type size_;
};
}  // namespace mo

#include "mo_queue.tpp"