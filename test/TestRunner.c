#include <stdlib.h>
#include <check.h>

int main(){
    int numberOfFailedTests;
    SRunner *suiteRunner = srunner_create(NULL);
    srunner_run_all(suiteRunner, CK_NORMAL);
    numberOfFailedTests = srunner_ntests_failed(suiteRunner);
    srunner_free(suiteRunner);

    return (numberOfFailedTests == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
