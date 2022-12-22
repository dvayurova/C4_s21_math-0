#include "s21_math.h"

long double s21_floor(double x) {
  long double res = (long long)x;
  if (x != x)
    res = s21_NAN;
  else if (x == s21_INF || x == -s21_INF)
    res = x == s21_INF ? s21_INF : -s21_INF;
  else {
    if (x < 0 && (x - res))
      res -= 1;
    if (1 / x == -s21_INF)
      res = x;
  }
  return res;
}