#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "RomanNumeralConverter.h"

int const arabicValues[13] = {1, 5, 10, 50, 100, 500, 1000};
char const *romanNumerals[13] = {"I", "V", "X", "L", "C", "D", "M"};

int getArabicValue(char roman){
    char romanString[2] = {roman, '\0'};
    for(int i = 0; i < 13; i++){
        if(strcmp(romanNumerals[i], romanString) == 0)
            return arabicValues[i];
    }
    return -1;
}

int toArabic(char* numeral){
    int value = 0;
    int previousValue = 0;
    for(int i = strlen(numeral) - 1 ; i >= 0 ; i--){
        int arabic = getArabicValue(numeral[i]);
        value += arabic < previousValue ? -arabic : arabic;
        previousValue = arabic;
    }
    return value;
}
