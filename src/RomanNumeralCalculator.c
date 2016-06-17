#include "RomanNumeralConverter.h"

char* addRomanNumerals(char* value1, char* value2){
    return toRoman(toArabic(value1) + toArabic(value2));
}

char* subtractRomanNumerals(char* value1, char* value2){
    return "";
}
