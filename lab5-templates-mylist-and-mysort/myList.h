#ifndef MYLIST_H
#define MYLIST_H

// Unlock tests
#define IMPLEMENTED_constructorOfEmptyList
#define IMPLEMENTED_pushingAndPopingElementsFront
#define IMPLEMENTED_nodesStoredAsUniquePtrs
#define IMPLEMENTED_popFromWhenEmptyList
#define IMPLEMENTED_copyingDisabled
#define IMPLEMENTED_removingElements
#define IMPLEMENTED_iteratorOperations
#define IMPLEMENTED_iteratorWithRangedForLoop
#define IMPLEMENTED_iteratorWithStlAlgorithm
#define IMPLEMENTED_ostreamOperator
// Unlock tests

#include <iostream>
#include <memory>
#include <stdexcept>
#include <iterator>

template<typename T>
class MyList {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  MyList() : head_(nullptr), size_(0) {}
  MyList(const MyList &) = delete;
  MyList &operator=(const MyList &) = delete;
  MyList(MyList &&) noexcept = default;
  MyList &operator=(MyList &&) noexcept = default;
  ~MyList() = default;

  [[nodiscard]] size_t size() const { return size_; }
  void push_front(const T &value);
  T pop_front();
  const T &front() const;

  class iterator;
  class const_iterator;
  [[nodiscard]] iterator begin();
  [[nodiscard]] iterator end();
  [[nodiscard]] const_iterator cbegin() const;
  [[nodiscard]] const_iterator cend() const;
  void remove(const T &value);

 private:
  struct Node;
  std::unique_ptr<Node> head_;
  size_t size_;

  template<typename U>
  friend std::ostream &operator<<(std::ostream &os, const MyList<U> &list);

  // For tests
  template<typename U>
  friend
  struct MyListTestWrapper;
};

template<typename T>
const T &MyList<T>::front() const {
  if (!head_) {
    throw std::out_of_range("List is empty");
  }
  return head_->data_;
}

template<typename T>
void MyList<T>::push_front(const T &value) {
  auto new_node = std::make_unique<Node>(value);
  new_node->next_ = std::move(head_);
  head_ = std::move(new_node);
  ++size_;
}

template<typename T>
T MyList<T>::pop_front() {
  if (!head_) {
    throw std::out_of_range("List is empty");
  }
  T value = head_->data_;
  head_ = std::move(head_->next_);
  --size_;
  return value;
}

template<typename T>
class MyList<T>::iterator {
 private:
  Node *current_;

 public:
  using iterator_category = std::forward_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = T *;
  using reference = T &;

  explicit iterator(Node *node) : current_(node) {}

  iterator &operator++() {
    if (current_) {
      current_ = current_->next_.get();
    }
    return *this;
  }

  iterator operator++(int) {
    iterator tmp = *this;
    ++(*this);
    return tmp;
  }

  T &operator*() const {
    return current_->data_;
  }

  T *operator->() const {
    return &(current_->data_);
  }

  bool operator==(const iterator &other) const {
    return current_ == other.current_;
  }

  bool operator!=(const iterator &other) const {
    return current_ != other.current_;
  }
};

template<typename T>
class MyList<T>::const_iterator {
 private:
  const Node *current_;

 public:
  using iterator_category = std::forward_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = const T *;
  using reference = const T &;

  explicit const_iterator(const Node *node) : current_(node) {}

  const_iterator &operator++() {
    if (current_) {
      current_ = current_->next_.get();
    }
    return *this;
  }

  const_iterator operator++(int) {
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
  }

  const T &operator*() const {
    return current_->data_;
  }

  const T *operator->() const {
    return &(current_->data_);
  }

  bool operator==(const const_iterator &other) const {
    return current_ == other.current_;
  }

  bool operator!=(const const_iterator &other) const {
    return current_ != other.current_;
  }
};

template<typename T>
typename MyList<T>::iterator MyList<T>::begin() {
  return iterator(head_.get());
}

template<typename T>
typename MyList<T>::iterator MyList<T>::end() {
  return iterator(nullptr);
}

template<typename T>
typename MyList<T>::const_iterator MyList<T>::cbegin() const {
  return const_iterator(head_.get());
}

template<typename T>
typename MyList<T>::const_iterator MyList<T>::cend() const {
  return const_iterator(nullptr);
}

template<typename T>
void MyList<T>::remove(const T &value) {
  Node *current = head_.get();
  Node *prev = nullptr;

  while (current) {
    if (current->data_ == value) {
      if (prev) {
        prev->next_ = std::move(current->next_);
        current = prev->next_.get();
      } else {
        head_ = std::move(current->next_);
        current = head_.get();
      }
      --size_;
    } else {
      prev = current;
      current = current->next_.get();
    }
  }
}

template<typename T>
struct MyList<T>::Node {
  T data_;
  std::unique_ptr<Node> next_;
  explicit Node(const T &data) : data_(data), next_(nullptr) {}
};

template<typename T>
std::ostream &operator<<(std::ostream &os, const MyList<T> &list) {
  for (auto it = list.cbegin(); it != list.cend(); ++it) {
    os << *it << " ";
  }
  return os;
}

#endif // MYLIST_H
