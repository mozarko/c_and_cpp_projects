#pragma once

namespace mo {

template <typename T>
vector<T>::vector() : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
vector<T>::vector(size_type n)
    : data_(new value_type[n]), size_(n), capacity_(n) {
  std::fill_n(data_, n, value_type());
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : data_(new value_type[items.size()]),
      size_(items.size()),
      capacity_(items.size()) {
  std::copy(items.begin(), items.end(), data_);
}

template <typename T>
vector<T>::vector(const vector &v)
    : data_(new value_type[v.capacity_]),
      size_(v.size_),
      capacity_(v.capacity_) {
  std::copy(v.data_, v.data_ + v.size_, data_);
}

template <typename T>
vector<T>::vector(vector &&v)

    noexcept
    : data_(v.data_), size_(v.size_), capacity_(v.capacity_) {
  v.data_ = nullptr;
  v.size_ = 0;
  v.capacity_ = 0;
}

template <typename T>
vector<T>::~vector() {
  delete[] data_;
  data_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <typename T>
vector<T> &vector<T>::operator=(vector &&v)

    noexcept {
  if (this != &v) {
    delete[] data_;
    data_ = v.data_;
    size_ = v.size_;
    capacity_ = v.capacity_;
    v.data_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
  }
  return *this;
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("IndexError: Index out of range");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("IndexError: Index out of range");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() {
  if (size_ == 0) throw std::out_of_range("FrontError: Vector is empty");
  return *data_;
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() {
  if (size_ == 0) throw std::out_of_range("BackError: Vector is empty");
  return data_[size_ - 1];
}

template <typename T>
T *vector<T>::data() {
  return data_;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return data_;
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return data_ + size_;
}

template <typename T>
bool vector<T>::empty() const {
  return size_ == 0;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() {
  return std::numeric_limits<value_type>::max() / sizeof(value_type);
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (capacity_ >= size) {
    return;
  }

  if (size > max_size()) {
    throw std::out_of_range("ReserveError: Too large size for a new capacity");
  }

  auto *new_data = new value_type[size];
  std::copy(data_, data_ + size_, new_data);
  delete[] data_;
  data_ = new_data;
  capacity_ = size;
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() const {
  return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    auto *new_data = new value_type[size_];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size_;
  }
}

template <typename T>
void vector<T>::clear() {
  for (size_t i = 0; i < size_; ++i) data_[i].~value_type();
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(const iterator pos,
                                               const_reference value) {
  size_type index = pos - begin();
  if (index > size_) {
    throw std::out_of_range("InsertError: Index out of range");
  }
  if (size_ == capacity_) {
    reserve(capacity_ ? capacity_ * 2 : 1);
  }
  push_back(value);
  for (size_type i = size_ - 1; i > index; --i) {
    std::swap(data_[i], data_[i - 1]);
  }
  return begin() + index;
}

template <typename T>
void vector<T>::erase(const iterator pos) {
  size_type index = pos - begin();
  if (index >= size_) {
    throw std::out_of_range("EraseError: Index out of range");
  }
  for (size_type i = index; i < size_ - 1; ++i) {
    std::swap(data_[i], data_[i + 1]);
  }
  pop_back();
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (size_ == capacity_) {
    reserve(capacity_ ? capacity_ * 2 : 1);
  }
  data_[size_++] = value;
}

template <typename T>
void vector<T>::pop_back() {
  if (size_ > 0) {
    data_[--size_].~T();
  }
}

template <typename T>
void vector<T>::swap(vector &other)

    noexcept {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename T>
bool vector<T>::operator==(vector const &other) const {
  int code = 1;
  if (size_ != other.size_) code = 0;
  for (size_type i = 0; i < size_; ++i) {
    if (data_[i] != other.data_[i]) code = 0;
  }
  return code;
}

// insert many
template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  vector<value_type> temp{args...};
  iterator cur_pos = begin() + (pos - begin());
  for (size_t i = 0; i < temp.size(); ++i) {
    cur_pos = insert(cur_pos, temp[i]);
    ++cur_pos;
  }
  return cur_pos;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  insert_many(end(), args...);
}

}  // namespace mo
