#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "RomanNumeralConverter.h"

int const arabicValues[3] = {1, 5, 10};
char const *romanNumerals[3] = {"I", "V", "X"};

int getArabicValue(char* roman){
    for(int i = 0; i < 3; i++){
        if(strcmp(romanNumerals[i], roman) == 0)
            return arabicValues[i];
    }
    return -1;
}

int toArabic(char* numeral){
    int value = 0;
    for(int i = 0; i < strlen(numeral); i++){
        char characterString[2] = {numeral[i], '\0'};
        value += getArabicValue(characterString);
    }
    return value;
}
