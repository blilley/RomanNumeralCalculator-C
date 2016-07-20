#include "RomanNumeralCalculator.h"
#include "RomanNumeralConverter.h"

static void clearString(char* string){
    string[0] = '\0';
}

int addRomanNumerals(char* output, const char* value1, const char* value2){
    clearString(output);
    int summation = toArabic(value1) + toArabic(value2);
    if(summation > MAX_ROMAN_NUMERAL)
        return CALCULATOR_ERROR_CODE;
    toRoman(output, summation);
    return CALCULATOR_SUCCESS_CODE;
}

int subtractRomanNumerals(char* output, const char* value1, const char* value2){
    clearString(output);
    int subtraction = toArabic(value1) - toArabic(value2);
    if(subtraction < MIN_ROMAN_NUMERAL)
        return CALCULATOR_ERROR_CODE;
    toRoman(output, toArabic(value1) - toArabic(value2));
    return CALCULATOR_SUCCESS_CODE;
}
