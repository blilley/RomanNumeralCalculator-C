#include "RomanNumeralConverter.h"

char* addRomanNumerals(const char* value1, const char* value2){
    return toRoman(toArabic(value1) + toArabic(value2));
}

char* subtractRomanNumerals(const char* value1, const char* value2){
    return toRoman(toArabic(value1) - toArabic(value2));
}
