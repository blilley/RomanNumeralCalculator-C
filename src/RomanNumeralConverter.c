#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "RomanNumeralConverter.h"

#define MAX_ROMAN_NUMERAL_LENGTH 16
#define MAX_LENGTH_FOR_LOOKUP 13
#define MAX_LENGTH_INVALID_NUMERALS 9

static const int arabicValues[MAX_LENGTH_FOR_LOOKUP] = {
    1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000
};
static const char *romanNumerals[MAX_LENGTH_FOR_LOOKUP] = {
    "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"
};

static const char *invalidNumerals[MAX_LENGTH_INVALID_NUMERALS] = {
    "IL", "IC", "ID", "IM", "XD", "XM", "LC", "LD", "LM"
};

static int getArabicValue(char roman){
    char romanString[2] = {roman, '\0'};
    for(int i = 0; i < MAX_LENGTH_FOR_LOOKUP; i++){
        if(strcmp(romanNumerals[i], romanString) == 0)
            return arabicValues[i];
    }
    return CONVERTER_ERROR_CODE;
}

static int checkForInvalidNumerals(const char* numeral){
    for(int i = 0; i < MAX_LENGTH_INVALID_NUMERALS; i++){
        if(strstr(numeral, invalidNumerals[i])!= NULL)
            return CONVERTER_ERROR_CODE;
    }
    return CONVERTER_SUCCESS_CODE;
}

static int isInvalidNumeral(int arabic, const char* numeral){
    char output[MAX_ROMAN_NUMERAL_LENGTH] = "\0";
    toRoman(output, arabic);

    return strcmp(output, numeral) != 0;
}

int toArabic(const char* numeral){
    if(checkForInvalidNumerals(numeral) == CONVERTER_ERROR_CODE)
        return CONVERTER_ERROR_CODE;

    int value = 0;
    int previousValue = 0;
    for(int i = strlen(numeral) - 1 ; i >= 0 ; i--){
        int arabic = getArabicValue(numeral[i]);
        value += arabic < previousValue ? -arabic : arabic;
        previousValue = arabic;
    }

    if(isInvalidNumeral(value, numeral))
        return CONVERTER_ERROR_CODE;

    return value;
}

int toRoman(char *output, int arabic){
    if(arabic > MAX_ROMAN_NUMERAL || arabic < MIN_ROMAN_NUMERAL)
        return CONVERTER_ERROR_CODE;

    for(int i = MAX_LENGTH_FOR_LOOKUP - 1; i >= 0; i--){
        while(arabic >= arabicValues[i]){
            arabic -= arabicValues[i];
            strcat(output, romanNumerals[i]);
        }
    }
    return CONVERTER_SUCCESS_CODE;
}
