#ifndef FUNCTION_H
#define FUNCTION_H
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
namespace oj {
	class BigInt {
			char *_val;
		public:
			BigInt(char *s);
			~BigInt();
			BigInt& operator++();
			BigInt operator++(int);
			BigInt& operator--();
			BigInt operator--(int);
			char* to_s();
	};
	char* BigInt::to_s() {
		char *ans;
		int len = strlen(_val);
		//std::cout << len << '\n';
		//ans = (char *) std::malloc(sizeof(char) * len + 20);
		ans = (char *) std::malloc(sizeof(char) * 1500);
		for (int i = 0; i < len; i++) {
			ans[i] = _val[len - i - 1];
		}
		ans[len] = '\0';
		return ans;
	}
	BigInt::BigInt(char *s) {
		int len = std::strlen(s);
		//_val = (char *) std::malloc(sizeof(char) * len + 20);
		_val = (char *) std::malloc(sizeof(char) * 1500);
		for (int i = 0; i < len; i++) {
			_val[i] = s[len - i - 1];
		}
		_val[len] = '\0';
	}
	BigInt::~BigInt() {
		//std::free(_val);
	}
	BigInt& BigInt::operator++ () {
		int i = 0, carry = 1;
		for (i = 0; i < std::strlen(_val) && carry >= 1; i++) {
			if (_val[i] + carry > '9') {
				_val[i] = '0';
			}
			else {
				_val[i] += carry;
				carry = 0;
			}
		}
		if (carry >= 1) {
			_val[i] = '1';
			_val[i + 1] = '\0';
		}
		return *this;
	}
	BigInt BigInt::operator++(int) {
		BigInt tmp = BigInt("");
		char ttt[1500];
		strcpy(ttt, this->_val);
		strcpy(tmp._val, ttt);
		//cout << "before: " << tmp._val << " " << this->_val << "\n";
		++(*this);
		//cout << "after: " << tmp._val << " " << this->_val << "\n";
		return tmp;
	}
	BigInt& BigInt::operator--() {
		if (strcmp("0", _val) == 0) return *this;
		int i = 0, carry = 1;
		for (i = 0; i < std::strlen(_val) && carry >= 1; i++) {
			if (_val[i] - carry < '0') {
				_val[i] = '9';
			}
			else {
				_val[i] -= carry;
				carry = 0;
			}
		}
		if (carry >= 1) {
			_val[i] = '9';
			_val[i + 1] = '\0';
		}
		for (i = strlen(_val) - 1; i > 0; i--) {
			if (_val[i] == '0') _val[i] = 0;
			else break;
		}
		return *this;
	}
	BigInt BigInt::operator--(int) {
		if (strcmp("0", _val) == 0) return *this;
		BigInt tmp = BigInt("");
		char ttt[strlen(this->_val)];
		strcpy(ttt, this->_val);
		strcpy(tmp._val, ttt);
		//cout << "before: " << tmp._val << " " << this->_val << "\n";
		--(*this);
		//cout << "after: " << tmp._val << " " << this->_val << "\n";
		return tmp;
	}
}  // namespace oj

#endif
