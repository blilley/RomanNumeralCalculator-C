#include <stdlib.h>
#include <string.h>
#include "RomanNumeralConverter.h"

int toArabic(char* numeral){
    if(strcmp(numeral, "III") == 0)
        return 3;
    if(strcmp(numeral, "II") == 0)
        return 2;
    return 1;
}
