#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "allocator.h"
#include "new.h"

namespace {
const size_t MAX_ITEMS_COUNT = 10;
} // namespace

int main(int argc, char *argv[]) {

  try {
#if 1
    auto m10 = std::map<
        int, int, std::less<int>,
        implacement_allocator_n<std::pair<const int, int>, MAX_ITEMS_COUNT>>{};

    for (int i = 0; i < 10; ++i) {
      m10[i] = i;
    }

    std::for_each(m10.begin(), m10.end(), [](const std::pair<int, int> &p) {
      std::cout << p.first << " -> " << p.second << std::endl;
    });
    std::cout << "\n";
#else
implacement_allocator_n<int, 10> alloc;
std::vector<int, implacement_allocator_n<int, 10>> v10(alloc);

  for (int i = 0; i < 10; i++)
  {
    v10.emplace_back(i);
  }
  std::for_each(v10.begin(), v10.end(), [](int val) {
    std::cout << val << " ";
  });
  std::cout << "\n";
#endif
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
