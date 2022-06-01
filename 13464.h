#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <iostream>
using std::string;

// TODO: please implement following overloaded functions
// Generally return 1 if the first parameter is greater than the second, 0 if the two ones are equal, -1 otherwise

int cmp(const string &, const string &);        // just compare the two strings
int cmp(const string &, const string &, int n); // compare the first n characters of two strings
int cmp(const string &, char);                  // compare the character and the string, considering the character as 1-lengthed string
int cmp(char, const string &);                  // similar with the above, only different in the order of the parameters
int cmp(char, const string &, int n);           // compare the character and the n-th character of the string
int cmp(const string &, char, int n);           // similar with the above, only different in the order of the parameters
int cmp(char, char);                            // just compare the two characters

int cmp(const string &a, const string &b) {
    if (a < b) return -1;
    if (a > b) return 1;
    else return 0;
}
int cmp(const string &a, const string &b, int n) {
    string sa = a.substr(0, n);
    string sb = b.substr(0, n);
    if (sa < sb) return -1;
    if (sa > sb) return 1;
    else return 0;
}
int cmp(const string &a, char b) {
    string sb;
    sb += b;
    if (a < sb) return -1;
    if (a > sb) return 1;
    else return 0;
}
int cmp(char a, const string &b) {
    string sa;
    sa += a;
    if (sa < b) return -1;
    if (sa > b) return 1;
    else return 0;
}
int cmp(char a, const string &b, int n) {
    char sb = b[n];
    if (a < sb) return -1;
    if (a > sb) return 1;
    else return 0;
}
int cmp(const string &a, char b, int n) {
    char sa = a[n];
    if (sa < b) return -1;
    if (sa > b) return 1;
    else return 0;
}
int cmp(char a, char b) {
    if (a < b) return -1;
    if (a > b) return 1;
    else return 0;
}

#endif // FUNCTION_H
