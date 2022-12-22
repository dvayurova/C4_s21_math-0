#include "s21_math.h"

long double s21_fabs(double x) {
  if (x == s21_INF || x == -s21_INF)
    x = s21_INF;
  if (x == s21_NAN || x == -s21_NAN)
    x = s21_NAN;
  else if (x < 0)
    x = -1 * x;
  return x;
}