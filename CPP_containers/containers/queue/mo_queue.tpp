#pragma once

namespace mo {

template <typename T>  // конструктор по умолчанию
queue<T>::queue() : front_(nullptr), back_(nullptr), size_(0) {}

template <typename T>  // конструктор инициализации
queue<T>::queue(std::initializer_list<value_type> const &items)
    : front_(nullptr), back_(nullptr), size_(0) {
  for (const auto &item : items) {
    push(item);
  }
}

template <typename T>  // конструктор копирования
queue<T>::queue(const queue &q) : front_(nullptr), back_(nullptr), size_(0) {
  Node *temp = q.front_;
  while (temp != nullptr) {
    push(temp->data);
    temp = temp->next;
  }
}

template <typename T>  // конструктор перемещения
queue<T>::queue(queue &&q) : front_(q.front_), back_(q.back_), size_(q.size_) {
  q.front_ = nullptr;
  q.back_ = nullptr;
  q.size_ = 0;
}

template <typename T>  // деструктор
queue<T>::~queue() {
  while (front_ != nullptr) {
    Node *temp = front_;
    front_ = front_->next;
    delete temp;
  }
  back_ = nullptr;
  size_ = 0;
}

template <typename T>  // оператор присваивания перемещением
queue<T> &queue<T>::operator=(queue &&q) {
  if (this != &q) {
    while (!empty()) {
      clear();
    }
    front_ = q.front_;
    back_ = q.back_;
    size_ = q.size_;

    q.front_ = nullptr;
    q.back_ = nullptr;
    q.size_ = 0;
  }
  return *this;
}

template <typename T>  // оператор присваивания копированием
queue<T> &queue<T>::operator=(const queue &q) {
  if (this != &q) {  // Проверка самоприсваивания
    // Копирование данных
    while (!empty()) {
      clear();
    }

    size_ = q.size_;
    // Если очередь не пустая, создаем новые элементы
    if (q.front_ != nullptr) {
      front_ = new Node(*q.front_);
      Node *current = front_;
      Node *q_current = q.front_->next;

      while (q_current != nullptr) {
        current->next = new Node(*q_current);  // Копируем следующий элемент
        current = current->next;
        q_current = q_current->next;
      }

      back_ = current;  // Устанавливаем back_ на последний элемент
    }
  }
  return *this;
}

template <typename T>
void queue<T>::clear() {
  if (empty()) throw std::out_of_range("Queue is empty");
  Node *temp = front_;
  front_ = front_->next;
  delete temp;
  --size_;
  if (front_ == nullptr) {
    back_ = nullptr;
  }
}

// Element access
template <typename T>
typename queue<T>::const_reference queue<T>::front() {
  if (front_ == nullptr) {
    throw std::out_of_range("Queue is empty");
  }
  return front_->data;
}

template <typename T>
typename queue<T>::const_reference queue<T>::back() {
  if (back_ == nullptr) {
    throw std::out_of_range("Queue is empty");
  }
  return back_->data;
}

// capacity

template <typename T>
bool queue<T>::empty() {
  return (front_ == nullptr && back_ == nullptr && size_ == 0);
}

template <typename T>
typename queue<T>::size_type queue<T>::size() {
  return size_;
}

// modifiers
template <typename T>
void queue<T>::push(const_reference value) {
  Node *new_node = new Node(value);
  if (front_ == nullptr) {
    front_ = new_node;
    back_ = new_node;
  } else {
    back_->next = new_node;
    back_ = new_node;
  }
  ++size_;
}

template <typename T>
void queue<T>::pop() {
  if (front_ == nullptr) {
    throw std::out_of_range("Queue is empty");
  }
  Node *temp = front_;
  front_ = front_->next;
  delete temp;
  --size_;
}

template <typename T>
void queue<T>::swap(queue &other) {
  std::swap(front_, other.front_);
  std::swap(back_, other.back_);
  std::swap(size_, other.size_);
}

// insert_many

template <typename T>
template <typename... Args>
void queue<T>::insert_many_back(Args &&...args) {
  for (const auto &arg : {args...}) {
    push(arg);
  }
}

}  // namespace mo
