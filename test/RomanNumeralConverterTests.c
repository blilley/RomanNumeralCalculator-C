#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "RomanNumeralConverterTests.h"
#include "../src/RomanNumeralConverter.h"
static void assertToRoman(int input, char* expected){
    char output[16] = "";
    toRoman(output, input);
    ck_assert_str_eq(output, expected);
}

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

START_TEST(test_toArabic_ReturnsErrorCode_WithInvalidInput)
{
    ck_assert_int_eq(toArabic("Z"), -1);
    ck_assert_int_eq(toArabic("ZZ"), -1);
    ck_assert_int_eq(toArabic("A"), -1);
    ck_assert_int_eq(toArabic("ICM"), -1);
    ck_assert_int_eq(toArabic("CIC"), -1);
    ck_assert_int_eq(toArabic("CLCLC"), -1);
    ck_assert_int_eq(toArabic("VIV"), -1);
    ck_assert_int_eq(toArabic("LXL"), -1);
    ck_assert_int_eq(toArabic("IL"), -1);
    ck_assert_int_eq(toArabic("IC"), -1);
    ck_assert_int_eq(toArabic("ID"), -1);
    ck_assert_int_eq(toArabic("IM"), -1);
    ck_assert_int_eq(toArabic("XD"), -1);
    ck_assert_int_eq(toArabic("XM"), -1);
    ck_assert_int_eq(toArabic("LD"), -1);
    ck_assert_int_eq(toArabic("LM"), -1);
}
END_TEST

START_TEST(test_toRoman_ReturnsExpected)
   {
       assertToRoman(1, "I");
       assertToRoman(2, "II");
       assertToRoman(4, "IV");
       assertToRoman(5, "V");
       assertToRoman(999, "CMXCIX");
       assertToRoman(440, "CDXL");
       assertToRoman(3999, "MMMCMXCIX");

   }
END_TEST

START_TEST(test_toRoman_ReturnsErrorCode_WithInvalidInput)
   {
       char result[16] = "";
       ck_assert_int_eq(toRoman(result, 4000), -1);
       ck_assert_int_eq(toRoman(result, 0), -1);
       ck_assert_int_eq(toRoman(result, -1), -1);
   }
END_TEST

Suite* romanNumeralConverterSuite(void)
{
   Suite* suite = suite_create("Roman Numeral Converter Tests");
   TCase* toArabicTestCase = tcase_create("Convert Roman Numeral to Arabic");
   tcase_add_test(toArabicTestCase, test_toArabic_ReturnsExpected);
   suite_add_tcase(suite, toArabicTestCase);
   TCase* toArabicInvalidTestCase = tcase_create("Convert Roman Numeral to Arabic Invalid inputs");
   tcase_add_test(toArabicInvalidTestCase, test_toArabic_ReturnsErrorCode_WithInvalidInput);
   suite_add_tcase(suite, toArabicInvalidTestCase);

   TCase* toRomanTestCase = tcase_create("Convert Arabic to Roman Numeral");
   tcase_add_test(toRomanTestCase, test_toRoman_ReturnsExpected);
   suite_add_tcase(suite, toRomanTestCase);
   TCase* toRomanInvalidInputTestCase = tcase_create("Convert Arabic to Roman Numeral Invalid inputs");
   tcase_add_test(toRomanInvalidInputTestCase, test_toRoman_ReturnsErrorCode_WithInvalidInput);
   suite_add_tcase(suite, toRomanInvalidInputTestCase);

   return suite;
}
