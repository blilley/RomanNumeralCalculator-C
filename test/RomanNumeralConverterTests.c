#include <stdlib.h>
#include <check.h>
#include "RomanNumeralConverterTests.h"

Suite* romanNumeralConverterSuite(void)
{
   Suite* suite = suite_create("Roman Numeral Converter Tests");
   TCase* testCase = tcase_create("Convert Arabic to Roman Numerals");
   suite_add_tcase(suite, testCase);

   return suite;
}
