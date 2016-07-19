#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "RomanNumeralCalculatorTests.h"
#include "../src/RomanNumeralCalculator.h"

char result[16];

void setup(){
    result[0] = '\0';
}

START_TEST(test_addTwoI_ReturnsII){
    ck_assert_int_eq(addRomanNumerals(result, "I", "I"), 0);
    ck_assert_str_eq(result, "II");
}
END_TEST

START_TEST(test_addTwoII_ReturnsIV){
    ck_assert_int_eq(addRomanNumerals(result, "II", "II"), 0);
    ck_assert_str_eq(result, "IV");
}
END_TEST

START_TEST(test_addMMXAndXVI_ReturnsMMXXVI){
       ck_assert_int_eq(addRomanNumerals(result, "MMX", "XVI"), 0);
       ck_assert_str_eq(result, "MMXXVI");
}
END_TEST

START_TEST(test_subtractIIAndI_ReturnsI){
       ck_assert_int_eq(subtractRomanNumerals(result, "II", "I"), 0);
       ck_assert_str_eq(result, "I");
}
END_TEST

START_TEST(test_subtractXAndVI_ReturnsIV){
       ck_assert_int_eq(subtractRomanNumerals(result, "X", "VI"), 0);
       ck_assert_str_eq(result, "IV");
}
END_TEST

START_TEST(test_subtractDAndC_ReturnsCD){
       ck_assert_int_eq(subtractRomanNumerals(result, "D", "C"), 0);
       ck_assert_str_eq(result, "CD");
}
END_TEST

START_TEST(test_addition_Exceeds3999_ReturnsError){
       ck_assert_int_eq(addRomanNumerals(result, "MMMCMXCVIII", "II"), -1);
}
END_TEST

START_TEST(test_subtraction_lessThan1_ReturnsError){
       printf("Test\n");
       ck_assert_int_eq(subtractRomanNumerals(result, "I", "I"), -1);
}
END_TEST

Suite* romanNumeralCalculatorSuite(void)
{
   Suite* suite = suite_create("Roman Numeral Calculator Tests");
   TCase* additionTestCase = tcase_create("Addition Calculator Tests");
   tcase_add_checked_fixture(additionTestCase, setup, NULL);
   tcase_add_test(additionTestCase, test_addTwoI_ReturnsII);
   tcase_add_test(additionTestCase, test_addTwoII_ReturnsIV);
   tcase_add_test(additionTestCase, test_addMMXAndXVI_ReturnsMMXXVI);
   suite_add_tcase(suite, additionTestCase);

   TCase* additionExceedingCaseTestCase = tcase_create("Addition Calculator Tests Result To Large");
   tcase_add_checked_fixture(additionExceedingCaseTestCase, setup, NULL);
   tcase_add_test(additionExceedingCaseTestCase, test_addition_Exceeds3999_ReturnsError);
   suite_add_tcase(suite, additionExceedingCaseTestCase);

   TCase* subtractionTestCase = tcase_create("Subtraction Calculator Tests");
   tcase_add_checked_fixture(subtractionTestCase, setup, NULL);
   tcase_add_test(subtractionTestCase, test_subtractIIAndI_ReturnsI);
   tcase_add_test(subtractionTestCase, test_subtractXAndVI_ReturnsIV);
   tcase_add_test(subtractionTestCase, test_subtractDAndC_ReturnsCD);
   suite_add_tcase(suite, subtractionTestCase);

   TCase* subtractionLessThan1TestCase = tcase_create("Subtraction Calculator Tests Result To Small");
   tcase_add_checked_fixture(subtractionLessThan1TestCase, setup, NULL);
   tcase_add_test(subtractionLessThan1TestCase, test_subtraction_lessThan1_ReturnsError);
   suite_add_tcase(suite, subtractionLessThan1TestCase);

   return suite;
}
