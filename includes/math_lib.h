#ifndef CONSERVATORY_INCLUDES_MATH_LIB_H
#define CONSERVATORY_INCLUDES_MATH_LIB_H

#pragma once
#include <iostream>
#include <cmath>
#include <type_traits>

namespace mathlib {

#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))

template <typename T,
          class = typename std::enable_if<std::is_integral<T>::value>::type>
int16_t sign(T u)
{
  return 1 | (u >> (sizeof(typeof(u)) * CHAR_BIT - 1));
}

template <typename T,
          class = typename std::enable_if<std::is_integral<T>::value>::type>
bool diff_sign(T u, T v)
{
  return ((u ^ v) < 0);
}

template <typename T,
    class = typename std::enable_if<std::is_integral<T>::value>::type>
int gcd(T p, T q) {
  if (q == 0) return p;
  else return gcd(q, p % q);
}

template <typename T,
    class = typename std::enable_if<std::is_integral<T>::value>::type>
int gcd2(T p, T q) {
  while (q != 0) {
    int temp = q;
    q = p % q;
    p = temp;
  }
  return p;
}

}
#endif //CONSERVATORY_INCLUDES_MATH_LIB_H
