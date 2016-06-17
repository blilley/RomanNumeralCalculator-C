#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "RomanNumeralCalculatorTests.h"
#include "../src/RomanNumeralCalculator.h"

void assertEqual(char* actual, char* expected){
    ck_assert_str_eq(actual, expected);
    free(actual);
}

START_TEST(test_addition_ReturnsExpected)
   {
       assertEqual(addRomanNumerals("I", "I"), "II");
       assertEqual(addRomanNumerals("II", "II"), "IV");
       assertEqual(addRomanNumerals("MMX", "XVI"), "MMXXVI");
   }
END_TEST

START_TEST(test_subtraction_ReturnsExpected)
   {
       assertEqual(subtractRomanNumerals("II", "I"), "I");
       assertEqual(subtractRomanNumerals("X", "VI"), "IV");
       assertEqual(subtractRomanNumerals("D", "C"), "CD");

   }
END_TEST

Suite* romanNumeralCalculatorSuite(void)
{
   Suite* suite = suite_create("Roman Numeral Calculator Tests");
   TCase* additionTestCase = tcase_create("Addition Calculator Tests");
   tcase_add_test(additionTestCase, test_addition_ReturnsExpected);
   suite_add_tcase(suite, additionTestCase);

   TCase* subtractionTestCase = tcase_create("Subtraction Calculator Tests");
   tcase_add_test(subtractionTestCase, test_subtraction_ReturnsExpected);
   suite_add_tcase(suite, subtractionTestCase);

   return suite;
}
