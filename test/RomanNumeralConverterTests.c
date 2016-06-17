#include <stdlib.h>
#include <check.h>
#include "RomanNumeralConverterTests.h"
#include "../src/RomanNumeralConverter.h"

START_TEST(test_toArabic_ReturnsExpected)
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
       ck_assert_int_eq(toArabic("M"), 1000);
       ck_assert_int_eq(toArabic("CMXCIX"), 999);
       ck_assert_int_eq(toArabic("MMXVI"), 2016);
       ck_assert_int_eq(toArabic("LXXIV"), 74);
   }
END_TEST

START_TEST(test_toRoman_ReturnsExpected)
   {
       ck_assert_str_eq(toRoman(1), "I");
   }
END_TEST

Suite* romanNumeralConverterSuite(void)
{
   Suite* suite = suite_create("Roman Numeral Converter Tests");
   TCase* toArabicTestCase = tcase_create("Convert Roman Numeral to Arabic");
   tcase_add_test(toArabicTestCase, test_toArabic_ReturnsExpected);
   suite_add_tcase(suite, toArabicTestCase);

   TCase* toRomanTestCase = tcase_create("Convert Arabic to Roman Numeral");
   tcase_add_test(toRomanTestCase, test_toRoman_ReturnsExpected);
   suite_add_tcase(suite, toRomanTestCase);

   return suite;
}
