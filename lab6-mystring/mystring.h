#ifndef MYSTRING_H
#define MYSTRING_H

#include <string>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <functional>

class MyString {
 public:
  // From `README.md`
  MyString(const char *text = "");
  MyString(const MyString &text);
  [[nodiscard]] std::string::iterator begin();
  [[nodiscard]] size_t capacity() const;
  [[nodiscard]] std::string::const_iterator cbegin() const;
  [[nodiscard]] std::string::const_iterator cend() const;
  [[nodiscard]] bool empty() const;
  [[nodiscard]] std::string::iterator end();
  bool operator==(const MyString &string) const;
  bool operator!=(const MyString &string) const;
  char operator[](size_t i) const;
  explicit operator std::string() const;
  void push_back(char c);
  [[nodiscard]] size_t size() const;
  [[nodiscard]] std::map<MyString, size_t> countWordsUsageIgnoringCases() const;
  bool all_of(std::function<bool(char)> predicate) const;
  static MyString generateRandomWord(size_t length);
  [[nodiscard]] std::set<MyString> getUniqueWords() const;
  [[nodiscard]] MyString join(const std::vector<MyString> &texts) const;
  bool startsWith(const char *text) const;
  MyString &toLower();
  MyString &trim();

  // For `myStringTests.cpp`
  MyString &clear();
  MyString &operator+=(const char &text);
  [[nodiscard]] bool endsWith(const MyString &string) const;
  bool operator<(const MyString &string) const;

  friend std::ostream &operator<<(std::ostream &stream, const MyString &string);
  friend std::istream &operator>>(std::istream &stream, MyString &string);

  // For tests (should be private)
  static constexpr size_t initialBufferSize_ = 20;
  std::string buffer;
};

#endif //MYSTRING_H
