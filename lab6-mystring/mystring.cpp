#include "mystring.h"
#include <algorithm>
#include <cctype>
#include <random>
#include <sstream>
#include <utility>

MyString::MyString(const char *text) {
  buffer.reserve(initialBufferSize_ + std::string().capacity());
  buffer = text;
}

MyString::MyString(const MyString &text) {
  buffer.reserve(initialBufferSize_ + std::string().capacity());
  buffer = text.buffer;
}

std::string::iterator MyString::begin() {
  return buffer.begin();
}

std::string::iterator MyString::end() {
  return buffer.end();
}

std::string::const_iterator MyString::cbegin() const {
  return buffer.cbegin();
}

std::string::const_iterator MyString::cend() const {
  return buffer.cend();
}

size_t MyString::size() const {
  return buffer.size();
}

size_t MyString::capacity() const {
  return buffer.capacity();
}

bool MyString::empty() const {
  return buffer.empty();
}

char MyString::operator[](size_t i) const {
  if (i >= buffer.size()) {
    throw std::out_of_range("Index out of range");
  }
  return buffer[i];
}

void MyString::push_back(char c) {
  buffer.push_back(c);
}

bool MyString::operator==(const MyString &string) const {
  return buffer == string.buffer;
}

bool MyString::operator!=(const MyString &string) const {
  return buffer != string.buffer;
}

MyString::operator std::string() const {
  return buffer;
}

std::map<MyString, size_t> MyString::countWordsUsageIgnoringCases() const {
  std::map<MyString, size_t> wordCount;
  std::string normalizedText = buffer;

  // Convert the text to lowercase
  std::transform(normalizedText.begin(), normalizedText.end(), normalizedText.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  // Replace non-alphanumeric characters with spaces
  std::replace_if(normalizedText.begin(), normalizedText.end(),
                  [](unsigned char c) { return !std::isalnum(c); }, ' ');

  // Split the text into words
  std::istringstream iss(normalizedText);
  std::string word;
  while (iss >> word) {
    MyString wordKey(MyString(word.c_str()));
    wordCount[wordKey]++;
  }
  return wordCount;
}

std::set<MyString> MyString::getUniqueWords() const {
  std::set<MyString> uniqueWords;
  std::map<MyString, size_t> wordCount = countWordsUsageIgnoringCases();

  for (const auto &entry : wordCount) {
    uniqueWords.insert(entry.first);
  }

  return uniqueWords;
}

bool MyString::all_of(std::function<bool(char)> predicate) const {
  return std::all_of(buffer.begin(), buffer.end(), std::move(predicate));
}

MyString MyString::generateRandomWord(size_t length) {
  const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const size_t maxIndex = sizeof(charset) - 1;
  std::string randomStr;
  randomStr.reserve(length);
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> dist(0, maxIndex - 1);
  for (size_t i = 0; i < length; ++i) {
    randomStr += charset[dist(generator)];
  }
  return {randomStr.c_str()};
}

MyString MyString::join(const std::vector<MyString> &texts) const {
  std::string result;
  for (auto it = texts.begin(); it != texts.end(); ++it) {
    result += it->buffer;
    if (it != texts.end() - 1) {
      result += buffer;
    }
  }
  return {result.c_str()};
}

bool MyString::startsWith(const char *text) const {
  std::string prefix(text);
  if (prefix.size() > buffer.size()) return false;

  auto result = std::search(buffer.begin(), buffer.end(), prefix.begin(), prefix.end());
  return result == buffer.begin();
}

bool MyString::endsWith(const MyString &string) const {
  if (string.size() > size()) return false;

  auto result = std::search(buffer.rbegin(), buffer.rend(), string.buffer.rbegin(), string.buffer.rend());
  return result == buffer.rbegin();
}

MyString &MyString::toLower() {
  std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
  return *this;
}

MyString &MyString::trim() {

  auto wsfront = std::find_if_not(buffer.begin(), buffer.end(), [](int c) {
    return std::isspace(c);
  });
  auto wsback = std::find_if_not(buffer.rbegin(), buffer.rend(), [](int c) {
    return std::isspace(c);
  }).base();

  buffer = wsback <= wsfront ? std::string() : std::string(wsfront, wsback);
  return *this;
}

MyString &MyString::clear() {
  buffer.clear();
  return *this;
}

MyString &MyString::operator+=(const char &text) {
  buffer += text;
  return *this;
}


bool MyString::operator<(const MyString &string) const {
  return buffer.compare(string.buffer) < 0;
}

std::ostream &operator<<(std::ostream &stream, const MyString &string) {
  stream << string.buffer;
  return stream;
}

std::istream &operator>>(std::istream &stream, MyString &string) {
  std::string temp;
  std::getline(stream, temp, '\0');
  string.buffer = temp;
  return stream;
}
