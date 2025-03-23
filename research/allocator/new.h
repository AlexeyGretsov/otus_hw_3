#pragma once

#include <cstdlib>
#include <iostream>
#include <memory>

void *operator new(std::size_t size) {
  std::cout << "new(std::size_t): " << size << std::endl;

  if (void *p = std::malloc(size)) {
    return p;
  }

  throw std::bad_alloc();
}

void *operator new[](std::size_t size) {
  std::cout << "new[](std::size_t): " << size << std::endl;

  if (void *p = std::malloc(size)) {
    return p;
  }

  throw std::bad_alloc();
}

void *operator new(std::size_t size,
                   const std::nothrow_t &nothrow_value) noexcept {
  std::cout << "new(std::size_t, std::nothrow_t): " << size << std::endl;

  return std::malloc(size);
}

void operator delete(void *p) {
  std::cout << "delete()" << std::endl;
  std::free(p);
}

void operator delete[](void *p) {
  std::cout << "delete[]()" << std::endl;
  std::free(p);
}
