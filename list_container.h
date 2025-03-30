#include <iostream>
#include <memory>
#include <utility>

template <typename T, typename Allocator = std::allocator<T>>
class ListContainer {
private:
  struct Node {
    T data;
    Node *next;

    template <typename... Args>
    Node(Args &&...args) : data(std::forward<Args>(args)...), next(nullptr) {}
  };

  Node *head = nullptr;
  Node *tail = nullptr;

  using NodeAllocator =
      typename std::allocator_traits<Allocator>::template rebind_alloc<Node>;
  NodeAllocator allocator;

public:
  using value_type = T;
  using allocator_type = Allocator;

  explicit ListContainer(const Allocator &alloc = Allocator())
      : allocator(alloc) {}

  ~ListContainer() {}

  template <typename... Args> void push_front(Args &&...args) {
    Node *newNode = createNode(std::forward<Args>(args)...);
    newNode->next = head;
    head = newNode;
    if (not tail) {
      tail = newNode;
    }
  }

  template <typename... Args> void push_back(Args &&...args) {
    Node *newNode = createNode(std::forward<Args>(args)...);
    if (not head) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  class Iterator {
  private:
    Node *current;

  public:
    explicit Iterator(Node *node) : current(node) {}

    Iterator &operator++() {
      if (current) {
        current = current->next;
      }
      return *this;
    }

    Iterator operator++(int) {
      Iterator temp = *this;
      ++(*this);
      return temp;
    }

    T &operator*() const { return current->data; }

    T *operator->() const { return &current->data; }

    bool operator==(const Iterator &other) const {
      return current == other.current;
    }

    bool operator!=(const Iterator &other) const { return !(*this == other); }
  };

  Iterator begin() const { return Iterator(head); }

  Iterator end() const { return Iterator(nullptr); }

  allocator_type get_allocator() const { return allocator; }

private:
  template <typename... Args> Node *createNode(Args &&...args) {
    Node *newNode =
        std::allocator_traits<NodeAllocator>::allocate(allocator, 1);
    std::allocator_traits<NodeAllocator>::construct(
        allocator, newNode, std::forward<Args>(args)...);
    return newNode;
  }
};
