#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "allocator.h"
#include "list_container.h"

// #define PRINT_SIMPLE_TYPES

namespace {
const size_t MAX_ITEMS_COUNT = 10;

int factorial(int n) {
  if (n < 0) {
    throw std::invalid_argument("invalid factorial number");
  }

  int res = 1;
  for (int i = 2; i <= n; i++)
    res *= i;
  return res;
}
} // namespace

int main(int argc, char *argv[]) {

  try {
    // Simple map
    auto m = std::map<int, int>{};

    // Fill simple map
    for (int i = 0; i < 10; ++i) {
      m[i] = factorial(i);
    }

#ifdef PRINT_SIMPLE_TYPES
    // Print simple map
    std::for_each(m.begin(), m.end(), [](const std::pair<int, int> &p) {
      std::cout << p.first << " " << p.second << std::endl;
    });
#endif
    // Map with custom allocator
    auto m10 = std::map<
        int, int, std::less<int>,
        implacement_allocator_n<std::pair<const int, int>, MAX_ITEMS_COUNT>>{};

    // Fill map with custom allocator
    for (int i = 0; i < 10; ++i) {
      m10[i] = factorial(i);
    }

    // Print map with custom allocator
    std::for_each(m10.begin(), m10.end(), [](const std::pair<int, int> &p) {
      std::cout << p.first << " " << p.second << std::endl;
    });

    // Custom list container
    auto cont = ListContainer<int>{};

    // Fill custom list container
    for (int i = 0; i < 10; i++) {
      cont.push_back(i);
    }

#ifdef PRINT_SIMPLE_TYPES
    // Print custom list container
    std::for_each(cont.begin(), cont.end(),
                  [](int item) { std::cout << item << ' '; });
    std::cout << "\n";
#endif
    // Custom list container with custom allocator
    auto cont10 =
        ListContainer<int, implacement_allocator_n<int, MAX_ITEMS_COUNT>>{};

    // Fill custom list container with custom allocator
    for (int i = 0; i < 10; i++) {
      cont10.push_back(i);
    }

    // Print custom list container with custom allocator
    std::for_each(cont10.begin(), cont10.end(),
                  [](int item) { std::cout << item << ' '; });
    std::cout << "\n";

  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
