#include <stdlib.h>
#include <check.h>
#include "RomanNumeralConverterTests.h"

int toArabicFromString(char* numeral){
    return -1;
}

START_TEST(test_standardRomanNumerals_ReturnsExpected)
   {
       ck_assert_int_eq(toArabicFromString("I"), 1);
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
