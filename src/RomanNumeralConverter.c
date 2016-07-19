#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "RomanNumeralConverter.h"

#define MAX_ROMAN_NUMERAL_LENGTH 16
#define MAX_LENGTH_FOR_LOOKUP 13
#define MAX_LENGTH_INVALID_NUMERALS 4
#define ERROR_CODE -1
#define SUCCESS 1

int const arabicValues[MAX_LENGTH_FOR_LOOKUP] = {
    1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000
};
char const *romanNumerals[MAX_LENGTH_FOR_LOOKUP] = {
    "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"
};

char const *invalidNumerals[MAX_LENGTH_INVALID_NUMERALS] = {
    "IL", "IC", "ID", "LC"
};

int getArabicValue(char roman){
    char romanString[2] = {roman, '\0'};
    for(int i = 0; i < MAX_LENGTH_FOR_LOOKUP; i++){
        if(strcmp(romanNumerals[i], romanString) == 0)
            return arabicValues[i];
    }
    return ERROR_CODE;
}
int checkForInvalidNumerals(const char* numeral){
    for(int i = 0; i < MAX_LENGTH_INVALID_NUMERALS; i++){
        if(strstr(numeral, invalidNumerals[i])!= NULL)
            return ERROR_CODE;
    }
    return SUCCESS;
}

int isATenValue(int value){
    while(value >= 10){
        value /= 10;
    }
    return value == 1;
}

int isNextValueValid(int previousValue, int index, const char* numeral){
    if(index-1 < 0 )
        return SUCCESS;
    int arabic = getArabicValue(numeral[index-1]);
    if(previousValue > arabic || (previousValue == arabic && !isATenValue(arabic)))
        return ERROR_CODE;

    return SUCCESS;
}

int nextValueIsInvalid(int arabic, int previousValue, int index, const char* numeral){
    return arabic < previousValue && isNextValueValid(previousValue, index, numeral) == ERROR_CODE;
}

int toArabic(const char* numeral){
    if(checkForInvalidNumerals(numeral) == ERROR_CODE)
        return ERROR_CODE;

    int value = 0;
    int previousValue = 0;
    for(int i = strlen(numeral) - 1 ; i >= 0 ; i--){
        int arabic = getArabicValue(numeral[i]);
        if(arabic < 1 || nextValueIsInvalid(arabic, previousValue, i, numeral))
            return ERROR_CODE;
        value += arabic < previousValue ? -arabic : arabic;
        previousValue = arabic;
    }
    return value;
}

void toRoman(char *output, int arabic){
    for(int i = MAX_LENGTH_FOR_LOOKUP - 1; i >= 0; i--){
        while(arabic >= arabicValues[i]){
            arabic -= arabicValues[i];
            strcat(output, romanNumerals[i]);
        }
    }
}
