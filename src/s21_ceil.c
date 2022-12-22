#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = (long long)x;
  if (res == 0 && (x < 0 || x == -0))
    return -0.0;
  if (x < 0 || res == x)
    return res;
  return res + 1;
}