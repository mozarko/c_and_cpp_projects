#pragma once

namespace mo {
template <typename T>
class stack {
 public:
  // member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // member functions
  stack();  // default constructor, creates an empty stack
  stack(std::initializer_list<value_type> const
            &items);      // initializer list constructor, creates stack
                          // initizialized using std::initializer_list<T>
  stack(const stack &s);  // copy constructor
  stack(stack &&s);       // move constructor
  ~stack();               // destructor
  stack &operator=(
      stack &&s);  // assignment operator overload for moving an object
  stack &operator=(
      const stack &s);  // assignment operator overload for copying an object

  // Element access
  const_reference top();  // returns a reference to the top element

  // Capacity
  bool empty();      // returns true if the stack is empty
  size_type size();  // returns the number of elements in the stack

  // Modifiers
  void push(const_reference value);  // adds an element to the top of the stack
  void pop();               // removes an element from the top of the stack
  void clear();             // removes all elements from the stack
  void swap(stack &other);  // swaps the contents of two stacks

  // insert many
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  struct Node {
    value_type data;
    Node *next;
    explicit Node(const_reference value) : data(value), next(nullptr) {}
  };

  Node *top_;
  size_type size_;
};
}  // namespace mo

#include "mo_stack.tpp"