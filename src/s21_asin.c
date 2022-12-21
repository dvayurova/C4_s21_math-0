#include "s21_math.h"

long double s21_asin(double x) {
  long double res = 0;
  res = s21_atan(x / (s21_sqrt(1 - s21_pow(x, 2))));
  return res;
}