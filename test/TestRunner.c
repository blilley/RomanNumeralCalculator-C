#include <stdlib.h>
#include <check.h>
#include "RomanNumeralConverterTests.h"
#include "RomanNumeralCalculatorTests.h"

int main(){
    int numberOfFailedTests;
    Suite* converterSuite = romanNumeralConverterSuite();
    Suite* calculatorSuite = romanNumeralCalculatorSuite();
    SRunner *suiteRunner = srunner_create(converterSuite);
    srunner_add_suite(suiteRunner, calculatorSuite);
    srunner_run_all(suiteRunner, CK_NORMAL);
    numberOfFailedTests = srunner_ntests_failed(suiteRunner);
    srunner_free(suiteRunner);

    return (numberOfFailedTests == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
