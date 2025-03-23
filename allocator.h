#pragma once

#include <memory>

template <typename T> class implacement_allocator {
public:
  using value_type = T;

  static size_t pos;
  static constexpr size_t size = sizeof(T) * 1000;
  static uint8_t data[size];

  implacement_allocator() noexcept {}
  ~implacement_allocator() {}

  template <typename U>
  implacement_allocator(const implacement_allocator<U> &) noexcept {}

  T *allocate(size_t n) {
    if (pos + n > size)
      throw std::bad_alloc();

    size_t cur = pos;
    pos += n;
    return reinterpret_cast<T *>(data) + cur;
  }

  void deallocate(T *p, size_t n) {}
};

template <typename T> uint8_t implacement_allocator<T>::data[size];

template <typename T> size_t implacement_allocator<T>::pos = 0;

template <class T, class U>
constexpr bool operator==(const implacement_allocator<T> &a1,
                          const implacement_allocator<U> &a2) noexcept {
  return true;
}

template <class T, class U>
constexpr bool operator!=(const implacement_allocator<T> &a1,
                          const implacement_allocator<U> &a2) noexcept {
  return false;
}
