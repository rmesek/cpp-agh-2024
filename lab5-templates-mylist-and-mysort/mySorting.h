#ifndef MYSORTING_H
#define MYSORTING_H

#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>

// My implementation of bubble sort

template<typename T, size_t N>
void mySort(T (&array)[N]) {
  bool swapped;
  for (size_t i = 0; i < N - 1; ++i) {
    swapped = false;
    for (size_t j = 0; j < N - 1 - i; ++j) {
      if (array[j] > array[j + 1]) {
        std::swap(array[j], array[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) break;
  }
}

template<typename T>
void mySort(T &list) {
  using ValueType = typename std::iterator_traits<typename T::iterator>::value_type;
  std::vector<ValueType> temp(list.begin(), list.end());

  bool swapped;
  for (size_t i = 0; i < temp.size() - 1; ++i) {
    swapped = false;
    for (size_t j = 0; j < temp.size() - 1 - i; ++j) {
      if (temp[j] > temp[j + 1]) {
        std::swap(temp[j], temp[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) break;
  }

  std::copy(temp.begin(), temp.end(), list.begin());
}

template<size_t N, size_t M>
void mySort(char (&array)[N][M]) {
  bool swapped;
  for (size_t i = 0; i < N - 1; ++i) {
    swapped = false;
    for (size_t j = 0; j < N - 1 - i; ++j) {
      if (strcasecmp(array[j], array[j + 1]) > 0) {
        char temp[M];
        strcpy(temp, array[j]);
        strcpy(array[j], array[j + 1]);
        strcpy(array[j + 1], temp);
        swapped = true;
      }
    }
    if (!swapped) break;
  }
}

#endif // MYSORTING_H
