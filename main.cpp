#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "allocator.h"
#include "list_container.h"

namespace {
const size_t MAX_ITEMS_COUNT = 10;
} // namespace

int main(int argc, char *argv[]) {

  try {
    std::cout << "std::map with custom allocator:\n";

    auto m10 = std::map<
        int, int, std::less<int>,
        implacement_allocator_n<std::pair<const int, int>, MAX_ITEMS_COUNT>>{};

    for (int i = 0; i < 10; ++i) {
      std::cout << "Put item to the map ...\n";
      m10[i] = i + 10;
    }

    std::cout << "Map content:\n";
    std::for_each(m10.begin(), m10.end(), [](const std::pair<int, int> &p) {
      std::cout << p.first << " -> " << p.second << std::endl;
    });
    std::cout << "\n\n";

    std::cout << "Custom list container with custom allocator:" << std::endl;
    auto cont =
        ListContainer<int, implacement_allocator_n<int, MAX_ITEMS_COUNT>>{};

    for (int i = 0; i < 10; i++) {
      std::cout << "Put item to the custom list ...\n";
      cont.push_back(i);
    }

    std::cout << "Custom list content:\n";
    std::for_each(cont.begin(), cont.end(),
                  [](int item) { std::cout << item << ' '; });
    std::cout << "\n";

  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
