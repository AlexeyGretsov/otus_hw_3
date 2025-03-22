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

int main(int argc, char *argv[]) {
  std::cout << "Operator new overload test\n";

  int *i = new int(42);
  int *arr = new int[42];

  void *mem = ::operator new(42 * sizeof(int));
  int *arr2 = new (mem) int[42];

  int *i_nt = new (std::nothrow) int(43);

  std::cout << "i = " << *i << std::endl;
  std::cout << "i_nt = " << *i_nt << std::endl;

  delete i;
  delete i_nt;
  delete[] arr;
  delete[] arr2;

  return 0;
}
