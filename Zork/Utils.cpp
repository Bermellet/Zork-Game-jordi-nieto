#include "Utils.h"

// Comparators
bool Equals(const string& str1, const string& str2) {
	return equal(str1.begin(), str1.end(),
        str2.begin(), str2.end(),
        [](char str1, char str2) {
            return tolower(str1) == tolower(str2);
        });
}

bool EqualsCaseSensitive(const string& str1, const string& str2) {
    return equal(str1.begin(), str1.end(),
        str2.begin(), str2.end());
}

// String
void Trim(string& str1) {
    TrimRight(str1);
    TrimLeft(str1);
}

void TrimLeft(string& str1) {
    str1.erase(str1.begin(), find_if(str1.begin(), str1.end(),
        not1(ptr_fun<int, int>(isspace))));
}
void TrimRight(string& str1) {
    str1.erase(find_if(str1.rbegin(), str1.rend(),
        not1(ptr_fun<int, int>(isspace))).base(), str1.end());
}

void ToLower(string& str1) {
    transform(str1.begin(), str1.end(), str1.begin(),
        [](unsigned char c) { return tolower(c); });
}

void ToUpper(string& str1) {
    transform(str1.begin(), str1.end(), str1.begin(),
        [](unsigned char c) { return toupper(c); });
}

// Print
