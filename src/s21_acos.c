#include "s21_math.h"

long double s21_acos(double x) {
  long double res = 0;
  if (x >= 0 && x <= 1)
    res = s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  else
    res = S21_PI + s21_atan(s21_sqrt(1 - s21_pow(x, 2)) / x);
  return res;
}