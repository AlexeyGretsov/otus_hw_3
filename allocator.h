#pragma once

#include <memory>

#if 0
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
#endif

template <typename T, size_t items_number> class implacement_allocator_n {
  public:
    using value_type = T;
  
    static size_t pos;
    static constexpr size_t size = sizeof(T) * items_number;
    static uint8_t data[size];
  
    implacement_allocator_n() noexcept {}
    ~implacement_allocator_n() {}
  
    template <typename U, size_t u_items_number>
    implacement_allocator_n(const implacement_allocator_n<U, u_items_number> &) noexcept {}
  
    template<class U>
    struct rebind
    {
      using other = implacement_allocator_n<U, items_number>;
    };

    T *allocate(size_t n) {
      if (pos + n > size)
        throw std::bad_alloc();
  
      size_t cur = pos;
      pos += n;
      return reinterpret_cast<T *>(data) + cur;
    }
  
    void deallocate(T *p, size_t n) {}
  };
  
  template <typename T, size_t items_number> 
  uint8_t implacement_allocator_n<T, items_number>::data[size];
  
  template <typename T, size_t items_number> 
  size_t implacement_allocator_n<T, items_number>::pos = 0;
  
  template <class T, class U, size_t items_number_comp>
  constexpr bool operator==(const implacement_allocator_n<T, items_number_comp> &a1,
                            const implacement_allocator_n<U, items_number_comp> &a2) noexcept {
    return true;
  }
  
  template <class T, class U, size_t items_number_comp>
  constexpr bool operator!=(const implacement_allocator_n<T, items_number_comp> &a1,
                            const implacement_allocator_n<U, items_number_comp> &a2) noexcept {
    return false;
  }
  