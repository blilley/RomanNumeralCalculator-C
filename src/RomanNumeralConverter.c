#include <stdlib.h>
#include <string.h>
#include "RomanNumeralConverter.h"

int toArabic(char* numeral){
    int value = 0;
    for(int i = 0; i < strlen(numeral); i++){
        value++;
    }
    return value;
}
