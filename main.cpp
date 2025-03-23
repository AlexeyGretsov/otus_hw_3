#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "allocator.h"
#include "new.h"

int main(int argc, char *argv[]) {
  std::cout << "Allocators test\n";

  implacement_allocator<int> alloc;

  std::vector<int, implacement_allocator<int>> v(alloc);
  std::vector<float> v2;

  try {
    for (int i = 0; i < 100; i++) {
      v.emplace_back(i);
    }

    std::for_each(v.begin(), v.end(), [](int val) { std::cout << val << " "; });
    std::cout << "\n";

    for (int i = 0; i < 100; i++) {
      v2.emplace_back(i);
    }

    std::for_each(v2.begin(), v2.end(),
                  [](int val) { std::cout << val << " "; });
    std::cout << "\n";

    auto m = std::map<int, float, std::less<int>,
                      implacement_allocator<std::pair<const int, float>>>{};

    for (int i = 0; i < 1200; ++i) {
      m[i] = static_cast<float>(i);
    }

    std::for_each(m.begin(), m.end(), [](const std::pair<int, float> &p) {
      std::cout << p.first << " -> " << (p.second / 2) << std::endl;
    });
    std::cout << "\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}
