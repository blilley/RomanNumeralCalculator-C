#ifndef ROMAN_NUMERAL_CONVERTER_H
#define ROMAN_NUMERAL_CONVERTER_H
#define MAX_ROMAN_NUMERAL 3999
#define MIN_ROMAN_NUMERAL 1
#define CONVERTER_ERROR_CODE -1
#define CONVERTER_SUCCESS_CODE 0

int toArabic(const char* numeral);
int toRoman(char* output, int arabic);
#endif
