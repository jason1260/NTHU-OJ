#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main() {
    string name;
    while (getline(cin, name)) { //lots of input
        int index_f = 1, flag = 0;
        string parsed;
        string first = name.substr(0, name.find(' '));
        int sz = first.size();
        stringstream input(name);
        getline(input, parsed, ' ');
        while (getline(input, parsed, ' ')) {
            if (index_f >= sz || toupper(parsed[0]) != toupper(first[index_f])) {flag = 1; break;}
            else index_f++;
        }
        (!flag && index_f == sz) ? cout << "o'_'o\n" : cout << "QQ\n"; 
        name.clear();
    }
}