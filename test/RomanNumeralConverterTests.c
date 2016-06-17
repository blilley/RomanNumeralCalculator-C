#include <stdlib.h>
#include <check.h>
#include "RomanNumeralConverterTests.h"
#include "../src/RomanNumeralConverter.h"

START_TEST(test_standardRomanNumerals_ReturnsExpected)
   {
       ck_assert_int_eq(toArabic("I"), 1);
       ck_assert_int_eq(toArabic("II"), 2);
       ck_assert_int_eq(toArabic("III"), 3);
       ck_assert_int_eq(toArabic("IV"), 4);
       ck_assert_int_eq(toArabic("V"), 5);
       ck_assert_int_eq(toArabic("IX"), 9);
       ck_assert_int_eq(toArabic("X"), 10);
       ck_assert_int_eq(toArabic("L"), 50);
       ck_assert_int_eq(toArabic("C"), 100);
       ck_assert_int_eq(toArabic("D"), 500);
   }
END_TEST

Suite* romanNumeralConverterSuite(void)
{
   Suite* suite = suite_create("Roman Numeral Converter Tests");
   TCase* testCase = tcase_create("Convert Roman Numeral to Arabic for standard Numerals");
   tcase_add_test(testCase, test_standardRomanNumerals_ReturnsExpected);

   suite_add_tcase(suite, testCase);

   return suite;
}
