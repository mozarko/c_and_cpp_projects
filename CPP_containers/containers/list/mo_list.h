#pragma once

namespace mo {
template <typename T>
class list {
 public:
  // member type
  class List_iterator;
  class List_const_iterator;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = List_iterator;
  using const_iterator = List_const_iterator;
  using size_type = size_t;

  // member functions
  list();
  explicit list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  list &operator=(list &&l);

  // element access
  const_reference front();
  const_reference back();

  // iterators
  iterator begin();
  const_iterator cbegin() const;
  iterator end();
  const_iterator cend() const;

  // capacity
  bool empty();
  size_type size();
  size_type max_size();

  // modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  // insert_many
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
  template <typename... Args>
  void insert_many_front(Args &&...args);

 private:
  struct Node {
    value_type data_;
    Node *next_;
    Node *prev_;
    explicit Node(const_reference value)
        : data_(value), next_(nullptr), prev_(nullptr) {}
  };

  Node *front_;
  Node *back_;
  size_type size_;
};

template <typename T>
class list<T>::List_iterator {
 public:
  // member type
  using value_type = T;
  using reference = T &;
  using pointer = T *;
  using difference_type = std::ptrdiff_t;  // стандартный тип для представления
                                           // разности между указателями.
  using iterator_category =
      std::forward_iterator_tag;  // Реализация итератора как прямой итератор.
                                  // Поддерживает инкремент и разыменование. Не
                                  // поддерживает инкремент в обратном
                                  // направлении.

  // constructor
  explicit List_iterator(typename list<T>::Node *node) : node_(node) {}

  // operators
  reference operator*() const {
    return node_->data_;
  }  // оператор разыменования возвращает ссылку на данные элемента в узле

  List_iterator &operator++() {  // префиксный инкремент перемещает на след.
                                 // узел
    node_ = node_->next_;
    return *this;
  }

  List_iterator operator++(int) {  // Постфиксный оператор инкремента создает
                                   // временный итератор, инкрементирует текущий
                                   // итератор и возвращает временный итератор.
    List_iterator temp = *this;
    ++(*this);
    return temp;
  }
  bool operator==(const List_iterator &other) const {
    return node_ == other.node_;
  }  // оператор сравнения двух итераторов    bool operator!=(const
     // List_iterator &other) const { return !(*this == other); }
  bool operator!=(const List_iterator &other) const {
    return !(*this == other);
  }

  typename list<T>::Node *get_node() const {
    return node_;
  }  // возвращает указатель на узел, на который указывает итератор
 private:
  typename list<T>::Node *node_;
};

template <typename T>
class list<T>::List_const_iterator {
 public:
  // member type
  using value_type = T;
  using reference = const T &;
  using pointer = const T *;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::forward_iterator_tag;

  // constructor
  explicit List_const_iterator(const typename list<T>::Node *node)
      : node_(node) {}

  // operators
  reference operator*() const { return node_->data_; }

  List_const_iterator &operator++() {
    node_ = node_->next_;
    return *this;
  }

  List_const_iterator operator++(int) {
    List_const_iterator temp = *this;
    ++(*this);
    return temp;
  }

  bool operator==(const List_const_iterator &other) const {
    return node_ == other.node_;
  }

  bool operator!=(const List_const_iterator &other) const {
    return !(*this == other);
  }

  const typename list<T>::Node *cget_node() { return node_; }

 private:
  const typename list<T>::Node *node_;
};

}  // namespace mo

#include "mo_list.tpp"
