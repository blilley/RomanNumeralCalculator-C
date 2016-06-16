#include <stdlib.h>
#include <string.h>
#include "RomanNumeralConverter.h"

int toArabic(char* numeral){
    int value = 0;
    for(int i = 0; i < strlen(numeral); i++){
        if(numeral[i] == 'V')
            value += 5;
        else if(numeral[i] == 'X')
            value += 10;
        else
            value++;
    }
    return value;
}
