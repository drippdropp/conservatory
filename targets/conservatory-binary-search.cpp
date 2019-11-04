#include "math_lib.h"
#include <iostream>
#include <searching/binary_search.h>
#include <vector>

using namespace mathlib;

void test_sign();
void test_diff_sign();

int main() {
  test_sign();
  test_diff_sign();

  return 0;
}

void test_binary_search() {
  std::vector<int> vec = {1, -4, 3, 4, 22, -45, 0};
  BinarySearch::search(vec, 3);
}
void test_sign() {
  int i1 = 3234;
  int i2 = -234982;
  unsigned i3 = 342;
  int16_t i4 = -3499;
  int32_t i5 = 29834234;
  int32_t i6 = -29834234;
  long i7 = 2098342;
  long i8 = -32809384;

  assert(sign(i1) == 1);
  assert(sign(i2) == -1);
  assert(sign(i3) == 1);
  assert(sign(i4) == -1);
  assert(sign(i5) == 1);
  assert(sign(i6) == -1);
  assert(sign(i7) == 1);
  assert(sign(i8) == -1);
}
void test_diff_sign() {
  int i1 = 3234;
  int i2 = -234982;
  int16_t i3 = 342;
  int16_t i4 = -3499;
  int32_t i5 = 29834234;
  int32_t i6 = -29834234;
  long i7 = 2098342;
  long i8 = -32809384;
  uint16_t i9 = 23424;
  uint16_t i10 = 34;
  int32_t i11 = -234;
  int32_t i12 = -3454;

  assert(diff_sign(i1, i2) == true);
  assert(diff_sign(i3, i4) == true);
  assert(diff_sign(i5, i6) == true);
  assert(diff_sign(i7, i8) == true);
  assert(diff_sign(i5, i5) == false);
  assert(diff_sign(i9, i10) == false);
  assert(diff_sign(i11, i12) == false);


}