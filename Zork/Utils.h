#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <locale>

using namespace std;

// Comparators
bool Equals(const string& str1, const string& str2);
bool EqualsCaseSensitive(const string& str1, const string& str2);

// String
string Trim(string& str1);
string TrimLeft(string& str1);
string TrimRight(string& str1);

#endif // !UTILS_H