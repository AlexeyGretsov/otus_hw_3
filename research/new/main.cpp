#include "new.h"

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
