#include "s21_math.h"
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long double s21_atan(double x) {
  long double res = 0;
  long double series = 0;
  long double sum = 0;
  if (x == s21_INF || x == -s21_INF) {
    res = x < 0 ? -M_PI / 2 : M_PI / 2;
  } else if (x >= -1 && x <= 1) {
    for (int i = 0; i < 400; i++) {
      series = (pow(-1, i) * pow(x, 1 + 2 * i)) / (1 + 2 * i);
      res += series;
    }
  } else {
    for (int i = 0; i < 400; i++) {
      series = (pow(-1, i) * pow(x, -1 - 2 * i)) / (1 + 2 * i);
      sum += series;
    }
    // printf("\nsum=%Lf\n", sum);
    res = ((M_PI * sqrt(pow(x, 2))) / (2 * x)) - sum;
  }
  if (x == 1 || x == -1)
    res = x * 0.785398163;
  return res;
}

long double s21_asin(double x) {
  long double res = 0;
  res = s21_atan(x / (sqrt(1 - pow(x, 2))));
  return res;
}

long double s21_acos(double x) {
  long double res = 0;
  if (x >= 0 && x <= 1)
    res = s21_atan(sqrt(1 - pow(x, 2)) / x);
  else
    res = S21_PI + s21_atan(sqrt(1 - pow(x, 2)) / x);
  return res;
}
long double s21_ceil(double x) {
  long double res = (long long)x;
  if (x != x)
    res = s21_NAN;
  else if (x == s21_INF || x == -s21_INF)
    res = x == s21_INF ? s21_INF : -s21_INF;
  else {
    if (x > 0 && (x - res))
      res += 1;
    if (res == 0 && x < 0)
      res = -1 * res;
    if (1 / x == -s21_INF)
      res = x;
  }
  if (x >= LLONG_MAX)
    res = x;
  return res;
}

// long double s21_floor(double x) {
//   long double res = (long long)x;
//   if (x != x)
//     res = s21_NAN;
//   else if (x == s21_INF || x == -s21_INF)
//     res = x == s21_INF ? s21_INF : -s21_INF;
//   else {
//     if (x < 0 && (x - res))
//       res -= 1;
//   }
//   return res;
// }
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
  if (x >= LLONG_MAX)
    res = x;
  return res;
}

int s21_abs(int x) { return x >= 0 ? x : (-1) * x; }

long double s21_fabs(double x) {
  if (x == s21_INF || x == -s21_INF)
    x = s21_INF;
  if (x == s21_NAN || x == -s21_NAN)
    x = s21_NAN;
  else if (x < 0)
    x = -1 * x;
  return x;
}
int main() {
  printf("%Lf\n", s21_asin(5));
  printf("%f\n", asin(5));
}
