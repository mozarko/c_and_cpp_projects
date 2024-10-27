#pragma once

namespace mo {
template <typename T>
stack<T>::stack() : top_(nullptr), size_(0) {}

template <typename T>
stack<T>::stack(std::initializer_list<value_type> const &items)
    : top_(nullptr), size_(0) {
  for (const auto &it : items) {
    push(it);
  }
}

template <typename T>
stack<T>::stack(const stack &s) : top_(nullptr), size_(0) {
  Node *current = s.top_;
  Node *prev = nullptr;

  // Копируем элементы из другого стека
  while (current != nullptr) {
    Node *new_node = new Node(current->data);  // Создаем новый узел
    if (prev == nullptr) {
      top_ = new_node;  // Устанавливаем top_ на первый элемент
    } else {
      prev->next = new_node;  // Соединяем узлы
    }
    prev = new_node;  // Переходим к следующему узлу
    current = current->next;
  }
  size_ = s.size_;  // Копируем размер
}

template <typename T>
stack<T>::stack(stack &&s) : top_(s.top_), size_(s.size_) {
  s.top_ = nullptr;
  s.size_ = 0;
}

template <typename T>
stack<T>::~stack() {
  clear();
}

template <typename T>
stack<T> &stack<T>::operator=(stack &&s) {
  if (this != &s) {
    clear();
    top_ = s.top_;
    size_ = s.size_;
    s.top_ = nullptr;
    s.size_ = 0;
  }
  return *this;
}

template <typename T>
stack<T> &stack<T>::operator=(const stack &s) {
  if (this != &s) {  // Проверка самоприсваивания
    clear();         // Очистка текущего стека

    // Копирование элементов из другого стека
    Node *current = s.top_;
    Node *prev = nullptr;

    while (current != nullptr) {
      Node *new_node = new Node(current->data);  // Создаем новый узел
      if (prev == nullptr) {
        top_ = new_node;  // Устанавливаем top_ на первый элемент
      } else {
        prev->next = new_node;  // Соединяем узлы
      }
      prev = new_node;  // Переходим к следующему узлу
      current = current->next;
    }
    size_ = s.size_;  // Копируем размер
  }
  return *this;
}

template <typename T>
typename stack<T>::const_reference stack<T>::top() {
  if (empty()) {
    throw std::out_of_range("Stack is empty");
  }
  return top_->data;
}

template <typename T>
bool stack<T>::empty() {
  return top_ == nullptr;
}

template <typename T>
typename stack<T>::size_type stack<T>::size() {
  return size_;
}

template <typename T>
void stack<T>::push(const_reference value) {
  Node *new_node = new Node(value);
  if (top_ == nullptr) {
    top_ = new_node;
  } else {
    new_node->next = top_;
    top_ = new_node;
  }
  ++size_;
}

template <typename T>
void stack<T>::pop() {
  if (empty()) {
    throw std::out_of_range("Stack is empty");
  }
  Node *temp = top_;
  top_ = top_->next;
  delete temp;
  --size_;
}

template <typename T>
void stack<T>::clear() {
  while (!empty()) {
    pop();
  }
}

template <typename T>
void stack<T>::swap(stack &other) {
  std::swap(top_, other.top_);
  std::swap(size_, other.size_);
}

// insert many

template <typename T>
template <typename... Args>
void stack<T>::insert_many_back(Args &&...args) {
  for (const auto &arg : {args...}) {
    push(arg);
  }
}

}  // namespace mo
