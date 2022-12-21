#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// #include "s21_math.h"

// long double s21_atan(double x) {
//   long double res = 0;
//   long double series = 0;
//   long double sum = 0;
//   if (x == s21_INF || x == -s21_INF) {
//     res = x < 0 ? -S21_PI / 2 : S21_PI / 2;
//   } else if (x >= -1 && x <= 1) {
//     for (int i = 0; i < 500000; i++) {
//       series = (pow(-1, i) * pow(x, 1 + 2 * i)) / (1 + 2 * i);
//       res += series;
//     }
//   } else {
//     for (int i = 0; i < 500000; i++) {
//       series = (pow(-1, i) * pow(x, -1 - 2 * i)) / (1 + 2 * i);
//       sum += series;
//     }
//     // printf("\nsum=%Lf\n", sum);
//     res = ((S21_PI * sqrt(pow(x, 2))) / (2 * x)) - sum;
//   }
//   return res;
// }

// long double s21_asin(double x) {
//   long double res = 0;
//   res = atan(x / (sqrt(1 - pow(x, 2))));
//   return res;
// }

// long double s21_acos(double x) {
//   long double res = 0;
//   if (x >= 0 && x <= 1)
//     res = s21_atan(sqrt(1 - pow(x, 2)) / x);
//   else
//     res = S21_PI + s21_atan(sqrt(1 - pow(x, 2)) / x);
//   return res;
// }

int main() {
  printf("%f\n", asin(0));
  // printf("%Lf\n", s21_fabs(-10000));
}
