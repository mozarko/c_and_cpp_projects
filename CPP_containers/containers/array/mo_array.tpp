#ifndef mo_ARRAY_TPP
#define mo_ARRAY_TPP

namespace mo {

template <typename T, size_t N> array<T, N>::array() : size_(N) {}

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  std::copy(items.begin(), items.end(), data_);
}

template <typename T, size_t N> array<T, N>::array(const array &a) {
  if (this != &a) {
    std::copy(a.data_, a.data_ + N, data_);
    size_ = a.size_;
  }
}

template <typename T, size_t N> array<T, N>::array(array &&a) noexcept {
  std::move(a.data_, a.data_ + N, data_);
  size_ = a.size_;
  a.size_ = 0;
}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(array &&a) noexcept {
  if (this != &a) {
    std::move(a.data_, a.data_ + N, data_);
    size_ = a.size_;
    a.size_ = 0;
  }
  return *this;
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("IndexError: Index out of range");
  }
  return data_[pos];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("IndexError: Index out of range");
  }
  return data_[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::front() {
  if (size_ == 0)
    throw std::out_of_range("FrontError: Vector is empty");
  return data_[0];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::back() {
  if (size_ == 0)
    throw std::out_of_range("BackError: Vector is empty");
  return data_[size_ - 1];
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::data() {
  return data_;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
  return data_;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::end() {
  return data_ + size_;
}

template <typename T, size_t N> bool array<T, N>::empty() { return size_ == 0; }

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::size() {
  return size_;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::max_size() {
  return size();
}

template <typename T, size_t N> void array<T, N>::swap(array &other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
}

template <typename T, size_t N> void array<T, N>::fill(const_reference value) {
  for (size_type i = 0; i < N; i++) {
    data_[i] = value;
  }
}

}; // namespace mo

#endif