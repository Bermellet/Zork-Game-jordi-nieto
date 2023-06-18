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
string Trim(string& str1) {
    TrimRight(str1);
    TrimLeft(str1);
    return str1;
}

string TrimLeft(string& str1) {
    str1.erase(str1.begin(), find_if(str1.begin(), str1.end(),
        not1(ptr_fun<int, int>(isspace))));
    return str1;
}
string TrimRight(string& str1) {
    str1.erase(find_if(str1.rbegin(), str1.rend(),
        not1(ptr_fun<int, int>(isspace))).base(), str1.end());
    return str1;
}