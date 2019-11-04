#ifndef CONSERVATORY_INCLUDES_DATA_STRUCTURES_BINARY_SEARCH_H
#define CONSERVATORY_INCLUDES_DATA_STRUCTURES_BINARY_SEARCH_H

#include <iostream>
#include <cmath>
#include <type_traits>

class BinarySearch {
public:
  template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
  static long search(std::vector<T> elements, T target) {
    long index = 0;
    long low = 0;
    long high = elements.size() - 1;
    T index_value;

    while (low <= high) {
      index = low + (long) floor((high - low)/2);
      index_value = elements[index];
      if (index_value == target) return index;
      if (index_value < target) low = index + 1;
      if (index_value > target) high = index - 1;
    }
    return -1;
  }
};

#endif
