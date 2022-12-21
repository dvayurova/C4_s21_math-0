#include "s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  long double series = 0;
  long double sum = 0;
  if (x == s21_INF || x == -s21_INF) {
    res = x < 0 ? -S21_PI / 2 : S21_PI / 2;
  } else if (x >= -1 && x <= 1) {
    for (int i = 0; i < 500000; i++) {
      series = (s21_pow(-1, i) * s21_pow(x, 1 + 2 * i)) / (1 + 2 * i);
      res += series;
    }
  } else {
    for (int i = 0; i < 500000; i++) {
      series = (s21_pow(-1, i) * s21_pow(x, -1 - 2 * i)) / (1 + 2 * i);
      sum += series;
    }
    res = ((S21_PI * s21_sqrt(s21_pow(x, 2))) / (2 * x)) - sum;
  }
  return res;
}
