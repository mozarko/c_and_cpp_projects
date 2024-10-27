#pragma once

namespace mo {

template <typename T>
list<T>::list() : front_(nullptr), back_(nullptr), size_(0) {}

template <typename T>
list<T>::list(size_type n) : front_(nullptr), back_(nullptr), size_(0) {
  for (size_type i = 0; i < n; ++i) {
    push_back(T());
  }
}

template <typename T>
list<T>::list(std::initializer_list<value_type> const &items)
    : front_(nullptr), back_(nullptr), size_(0) {
  for (const auto &item : items) {
    push_back(item);
  }
}

template <typename T>
list<T>::list(const list &l) : front_(nullptr), back_(nullptr), size_(0) {
  for (auto it = l.cbegin(); it != l.cend(); ++it) {
    push_back(*it);
  }
}

template <typename T>
list<T>::list(list &&l) : front_(l.front_), back_(l.back_), size_(l.size_) {
  l.front_ = nullptr;
  l.back_ = nullptr;
  l.size_ = 0;
}

template <typename T>
list<T>::~list() {
  while (front_ != nullptr) {
    Node *temp = front_;
    front_ = front_->next_;
    delete temp;
  }
  back_ = nullptr;
  size_ = 0;
}

template <typename T>
list<T> &list<T>::operator=(list &&l) {
  if (this != &l) {
    clear();
    front_ = l.front_;
    back_ = l.back_;
    size_ = l.size_;
    l.front_ = nullptr;
    l.back_ = nullptr;
    l.size_ = 0;
  }
  return *this;
}

template <typename T>
typename list<T>::const_reference list<T>::front() {
  if (empty()) throw std::out_of_range("IndexError: Index out of range");
  return front_->data_;
}

template <typename T>
typename list<T>::const_reference list<T>::back() {
  if (empty()) throw std::out_of_range("IndexError: Index out of range");
  return back_->data_;
}

template <typename T>
typename list<T>::iterator list<T>::begin() {
  return iterator(front_);
}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const {
  return const_iterator(front_);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
  return iterator(back_->next_);
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() const {
  return const_iterator(back_->next_);
}

template <typename T>
bool list<T>::empty() {
  return size_ == 0;
}

template <typename T>
typename list<T>::size_type list<T>::size() {
  return size_;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

template <typename T>
void list<T>::clear() {
  while (front_ != nullptr) {
    Node *temp = front_;
    front_ = front_->next_;
    delete temp;
  }
  back_ = nullptr;
  size_ = 0;
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  Node *new_node = new Node(value);  // Создание нового узла
  if (pos == begin()) {  // Если вставляем в начало
    new_node->next_ = front_;
    if (front_ != nullptr) {
      front_->prev_ = new_node;
    }
    front_ = new_node;
    if (back_ == nullptr) {
      back_ = new_node;
    }
  } else if (pos == end()) {  // Если вставляем в конец
    back_->next_ = new_node;
    new_node->prev_ = back_;
    back_ = new_node;
  } else {  // Если вставляем в середину
    Node *current = pos.get_node();
    new_node->next_ = current;
    new_node->prev_ = current->prev_;
    current->prev_->next_ = new_node;
    current->prev_ = new_node;
  }
  ++size_;  // обновление размера после вставки
  return iterator(new_node);
}

template <typename T>
void list<T>::erase(iterator pos) {
  Node *current = pos.get_node();
  if (current == nullptr) {
    throw std::out_of_range("IndexError: Index out of range");
  }
  if (current == front_) {
    front_ = front_->next_;
    if (front_ != nullptr) {
      front_->prev_ = nullptr;
    }
  } else if (current == back_) {
    back_ = back_->prev_;
    back_->next_ = nullptr;
  } else {
    current->prev_->next_ = current->next_;
    current->next_->prev_ = current->prev_;
  }
  delete current;
  --size_;
}

template <typename T>
void list<T>::push_back(const_reference value) {
  Node *new_node = new Node(value);
  if (empty()) {
    front_ = new_node;
    back_ = new_node;
  } else {
    new_node->prev_ = back_;
    back_->next_ = new_node;
    back_ = new_node;
  }
  ++size_;
}

template <typename T>
void list<T>::pop_back() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  if (front_ == back_) {
    clear();
  } else {
    Node *temp = back_;
    back_ = back_->prev_;
    back_->next_ = nullptr;
    delete temp;
    --size_;
  }
}

template <typename T>
void list<T>::push_front(const_reference value) {
  Node *new_node = new Node(value);
  if (empty()) {
    front_ = new_node;
    back_ = new_node;
  } else {
    new_node->next_ = front_;
    front_->prev_ = new_node;
    front_ = new_node;
  }
  ++size_;
}

template <typename T>
void list<T>::pop_front() {
  if (empty()) {
    throw std::out_of_range("List is empty");
  }
  if (front_ == back_) {
    clear();
  } else {
    erase(begin());
  }
}

template <typename T>
void list<T>::swap(list &other) {
  std::swap(front_, other.front_);
  std::swap(back_, other.back_);
  std::swap(size_, other.size_);
}

template <typename T>
void list<T>::merge(list &other) {  // Слияние двух списков
  if (this != &other) {  // Проверка на самослияние
    sort();  // сортировки списков, для гарантии правильного порядка элементов
    other.sort();
    auto it = begin();  // инициализация итераторов
    auto other_it = other.begin();
    while (other_it != other.end()) {        // цикл объеденения
      if (it == end() || *other_it < *it) {  // условие вставки
        insert(it, *other_it);
        ++other_it;
      } else {
        ++it;
      }
    }
    other.clear();
  }
}

template <typename T>
void list<T>::splice(iterator pos, list &other) {
  if (this != &other) {
    for (auto it = other.begin(); it != other.end(); ++it) {
      insert(pos, *it);
    }
    other.clear();
  }
}

template <typename T>
void list<T>::reverse() {
  if (size_ > 1) {
    Node *left = front_;
    Node *right = back_;
    while (left != right && left->prev_ != right) {
      std::swap(left->data_, right->data_);
      left = left->next_;
      right = right->prev_;
    }
  }
}

template <typename T>
void list<T>::unique() {
  if (size_ > 1) {
    Node *current = front_->next_;
    Node const *prev = front_;
    while (current != nullptr) {
      if (current->data_ == prev->data_) {
        Node *next_node = current->next_;
        erase(mo::list<T>::iterator(current));
        current = next_node;
      } else {
        prev = current;
        current = current->next_;
      }
    }
  }
}

template <typename T>
void list<T>::sort() {
  if (size_ > 1) {
    bool swapped;
    Node *current;
    Node const *last_sorted = nullptr;
    do {
      swapped = false;
      current = front_;
      while (current->next_ != last_sorted) {
        if (current->data_ > current->next_->data_) {
          std::swap(current->data_, current->next_->data_);
          swapped = true;
        }
        current = current->next_;
      }
      last_sorted = current;
    } while (swapped);
  }
}

// insert_many

template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  iterator it(const_cast<Node *>(pos.cget_node()));
  for (const auto &arg : {args...}) {
    insert(it, arg);
  }
  return it;
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args &&...args) {
  insert_many(cend(), args...);
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args &&...args) {
  insert_many(cbegin(), args...);
}

}  // namespace mo
