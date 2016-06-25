#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "RomanNumeralConverter.h"

#define MAX_ROMAN_NUMERAL_LENGTH 15
#define MAX_LENGTH_FOR_LOOKUP 13

int const arabicValues[MAX_LENGTH_FOR_LOOKUP] = {
    1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000
};
char const *romanNumerals[MAX_LENGTH_FOR_LOOKUP] = {
    "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"
};

int getArabicValue(char roman){
    char romanString[2] = {roman, '\0'};
    for(int i = 0; i < MAX_LENGTH_FOR_LOOKUP; i++){
        if(strcmp(romanNumerals[i], romanString) == 0)
            return arabicValues[i];
    }
    return -1;
}

int toArabic(const char* numeral){
    int value = 0;
    int previousValue = 0;
    for(int i = strlen(numeral) - 1 ; i >= 0 ; i--){
        int arabic = getArabicValue(numeral[i]);
        value += arabic < previousValue ? -arabic : arabic;
        previousValue = arabic;
    }
    return value;
}

char* toRoman(int arabic){
    char *value = calloc (MAX_ROMAN_NUMERAL_LENGTH, sizeof(char));
    for(int i = MAX_LENGTH_FOR_LOOKUP; i >= 0; i--){
        while(arabic >= arabicValues[i]){
            arabic -= arabicValues[i];
            strcat(value, romanNumerals[i]);
        }
    }
    return value;
}
