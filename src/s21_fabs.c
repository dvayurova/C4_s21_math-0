#include "s21_math.h"

long double s21_fabs(double x) {
  if (x == s21_INF || x == -s21_INF) return s21_INF;
  if (x == s21_NAN || x == -s21_NAN) return s21_NAN;
  return x >= 0 ? x : (-1) * x;
}