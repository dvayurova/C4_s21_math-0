#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(abs_test) {
  ck_assert_int_eq(s21_abs(-1), abs(-1));
  ck_assert_int_eq(s21_abs(1), abs(1));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
  ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
  ck_assert_int_eq(s21_abs(-9223372036854775808), abs(-9223372036854775808));
  ck_assert_int_eq(s21_abs(9223372036854775808), abs(9223372036854775808));
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_ldouble_infinite(s21_fabs(s21_INF));
  ck_assert_ldouble_infinite(s21_fabs(-s21_INF));
  ck_assert_ldouble_nan(s21_fabs(s21_NAN));
  ck_assert_ldouble_nan(s21_fabs(-s21_NAN));
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.0), fabs(-0.0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.0), fabs(-1.0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_fabs(1.0), fabs(1.0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_fabs(0.5), fabs(0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.5), fabs(-0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.32414), fabs(-0.32414), 1e-10);
  ck_assert_ldouble_eq_tol(s21_fabs(0.32414), fabs(0.32414), 1e-10);
  ck_assert_ldouble_eq_tol(s21_fabs(123.324242423), fabs(123.324242423), 1e-10);
  ck_assert_ldouble_eq_tol(s21_fabs(0.000000000001), fabs(0.000000000001),
                           1e-20);
  ck_assert_ldouble_eq_tol(s21_fabs(-2147483647.32414143),
                           fabs(-2147483647.32414143), 1e-10);
  ck_assert_ldouble_eq_tol(s21_fabs(2147483647.32414143),
                           fabs(2147483647.32414143), 1e-10);
  ck_assert_ldouble_eq_tol(s21_fabs(-1000.0), fabs(-1000.0), 1e-10);
}
END_TEST

START_TEST(asin_test) {
  ck_assert_ldouble_nan(s21_asin(s21_INF));
  ck_assert_ldouble_nan(s21_asin(-s21_INF));
  ck_assert_ldouble_nan(s21_asin(s21_NAN));
  ck_assert_ldouble_nan(s21_asin(-s21_NAN));
  ck_assert_ldouble_nan(s21_asin(2));
  ck_assert_ldouble_nan(s21_asin(1000));
  ck_assert_ldouble_eq_tol(s21_asin(0.1), asin(0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_asin(-0.1), asin(-0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_asin(0.32414), asin(0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_asin(-0.32414), asin(-0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-10);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-10);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_asin(-0), asin(-0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_asin(0.000000000001), asin(0.000000000001),
                           1e-10);
  ck_assert_ldouble_eq_tol(s21_asin(0.0002347234), asin(0.0002347234), 1e-10);
}
END_TEST

START_TEST(acos_test) {
  ck_assert_ldouble_nan(s21_acos(s21_INF));
  ck_assert_ldouble_nan(s21_acos(-s21_INF));
  ck_assert_ldouble_nan(s21_acos(s21_NAN));
  ck_assert_ldouble_nan(s21_acos(-s21_NAN));
  ck_assert_ldouble_nan(s21_acos(2));
  ck_assert_ldouble_nan(s21_acos(1000));
  ck_assert_ldouble_eq_tol(s21_acos(0.1), acos(0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_acos(-0.1), acos(-0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_acos(0.32414), acos(0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_acos(-0.32414), acos(-0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-10);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-10);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_acos(-0), acos(-0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_acos(0.000000000001), acos(0.000000000001),
                           1e-10);
  ck_assert_ldouble_eq_tol(s21_acos(0.0002347234), acos(0.0002347234), 1e-10);
}
END_TEST

START_TEST(atan_test) {
  ck_assert_ldouble_nan(s21_atan(s21_NAN));
  ck_assert_ldouble_nan(s21_atan(-s21_NAN));
  ck_assert_ldouble_eq_tol(s21_atan(-s21_INF), atan(-s21_INF), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(s21_INF), atan(s21_INF), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(0.1), atan(0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(-0.1), atan(-0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(1.555325), atan(1.1), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(-1.555325), atan(-2.1), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(123.324242423), atan(123.324242423), 1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(0.000000000001), atan(0.000000000001),
                           1e-10);
  ck_assert_ldouble_eq_tol(s21_atan(65465476545647.4234),
                           atan(65465476545647.4234), 1e-10);
}
END_TEST

START_TEST(floor_test) {
  ck_assert_ldouble_infinite(s21_floor(s21_INF));
  ck_assert_ldouble_infinite(s21_floor(-s21_INF));
  ck_assert_ldouble_nan(s21_floor(s21_NAN));
  ck_assert_ldouble_nan(s21_floor(-s21_NAN));
  ck_assert_ldouble_eq_tol(s21_floor(0.0), floor(0.0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_floor(-0.0), floor(-0.0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_floor(-1.0), floor(-1.0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_floor(1.0), floor(1.0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_floor(0.5), floor(0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_floor(-0.5), floor(-0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_floor(-0.32414), floor(-0.32414), 1e-10);
  ck_assert_ldouble_eq_tol(s21_floor(0.32414), floor(0.32414), 1e-10);
  ck_assert_ldouble_eq_tol(s21_floor(123.324242423), floor(123.324242423),
                           1e-10);
  ck_assert_ldouble_eq_tol(s21_floor(-123.324242423), floor(-123.324242423),
                           1e-10);
  ck_assert_ldouble_eq_tol(s21_floor(0.000000000001), floor(0.000000000001),
                           1e-20);
  ck_assert_ldouble_eq_tol(s21_floor(-0.000000000001), floor(-0.000000000001),
                           1e-20);
  ck_assert_ldouble_eq_tol(s21_floor(-2147483647.32414143),
                           floor(-2147483647.32414143), 1e-10);
  ck_assert_ldouble_eq_tol(s21_floor(2147483647.32414143),
                           floor(2147483647.32414143), 1e-10);
  ck_assert_ldouble_eq_tol(s21_floor(-1000), floor(-1000), 1e-10);
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_ldouble_infinite(s21_ceil(s21_INF));
  ck_assert_ldouble_infinite(s21_ceil(-s21_INF));
  ck_assert_ldouble_nan(s21_ceil(s21_NAN));
  ck_assert_ldouble_nan(s21_ceil(-s21_NAN));
  ck_assert_ldouble_eq_tol(s21_ceil(0.0), ceil(0.0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.0), ceil(-0.0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_ceil(-1.0), ceil(-1.0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_ceil(1.0), ceil(1.0), 1e-10);
  ck_assert_ldouble_eq_tol(s21_ceil(0.5), ceil(0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.5), ceil(-0.5), 1e-10);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.32414), ceil(-0.32414), 1e-10);
  ck_assert_ldouble_eq_tol(s21_ceil(0.32414), ceil(0.32414), 1e-10);
  ck_assert_ldouble_eq_tol(s21_ceil(123.324242423), ceil(123.324242423), 1e-10);
  ck_assert_ldouble_eq_tol(s21_ceil(-123.324242423), ceil(-123.324242423),
                           1e-10);
  ck_assert_ldouble_eq_tol(s21_ceil(0.000000000001), ceil(0.000000000001),
                           1e-20);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.000000000001), ceil(-0.000000000001),
                           1e-20);
  ck_assert_ldouble_eq_tol(s21_ceil(-2147483647.32414143),
                           ceil(-2147483647.32414143), 1e-10);
  ck_assert_ldouble_eq_tol(s21_ceil(2147483647.32414143),
                           ceil(2147483647.32414143), 1e-10);
  ck_assert_ldouble_eq_tol(s21_ceil(-1000), ceil(-1000), 1e-10);
}
END_TEST

int main(void) {
  Suite *suite =
      suite_create("S21_TEST"); // создание наборов тестов и с именем S21_TEST
  SRunner *srunner = srunner_create(suite);

  TCase *abs_Test =
      tcase_create("abs_test"); // создание тестового примера с именем StrLen
  suite_add_tcase(suite, abs_Test); // добавление в тестовый набор
  tcase_add_test(abs_Test,
                 abs_test); // добавление тестовой функции в тестовый пример

  TCase *fabs_Test = tcase_create("fabs_test");
  suite_add_tcase(suite, fabs_Test);
  tcase_add_test(fabs_Test, fabs_test);

  TCase *asin_Test = tcase_create("asin_test");
  suite_add_tcase(suite, asin_Test);
  tcase_add_test(asin_Test, asin_test);

  TCase *acos_Test = tcase_create("acos_test");
  suite_add_tcase(suite, acos_Test);
  tcase_add_test(acos_Test, acos_test);

  TCase *atan_Test = tcase_create("atan_test");
  suite_add_tcase(suite, atan_Test);
  tcase_add_test(atan_Test, atan_test);

  TCase *floor_Test = tcase_create("floor_test");
  suite_add_tcase(suite, floor_Test);
  tcase_add_test(floor_Test, floor_test);

  TCase *ceil_Test = tcase_create("ceil_test");
  suite_add_tcase(suite, ceil_Test);
  tcase_add_test(ceil_Test, ceil_test);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
