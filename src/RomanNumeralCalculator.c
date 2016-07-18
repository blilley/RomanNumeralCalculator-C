#include "RomanNumeralConverter.h"
#define MAX_ROMAN_NUMERAL 3999
#define ERROR_CODE -1

int addRomanNumerals(char* output, const char* value1, const char* value2){
    output[0]= 0;
    int summation = toArabic(value1) + toArabic(value2);
    if(summation > MAX_ROMAN_NUMERAL)
        return ERROR_CODE;
    toRoman(output, summation);
    return 0;
}

int subtractRomanNumerals(char* output, const char* value1, const char* value2){
    output[0]= 0;
    int subtraction = toArabic(value1) - toArabic(value2);
    if(subtraction < 1)
        return ERROR_CODE;
    toRoman(output, toArabic(value1) - toArabic(value2));
    return 0;
}
