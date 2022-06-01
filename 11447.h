#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<map>
#include<string>
#include <iostream>
#include <set>
using namespace std;
namespace oj
{
	struct String
	{
		string str;
		String(const string &);
		String(const String &);
		String& operator=(const String &);
	};
	ostream& operator<<(ostream &,const String &);

	void insert(std::map<int,String> &ma,int key,const string &str) {
		pair<map<int, String>::iterator, bool> flag;
		flag = ma.emplace(pair<int, String> (key, str));
		if (!flag.second) {
			auto it = ma.find(key);
			string tmp = str + it->second.str;
			ma.erase(it);
			ma.insert(pair<int, String> (key, tmp));
		}
	}
	void output(const map<int,String> &ma,int begin,int end) {
		for (auto &it : ma) {
			if (it.first >= begin && it.first <= end) cout << it.second << ' ';
		}
	}
	void erase(map<int,String> &ma,int begin,int end) {
		set<int> erase_idx;
		for (auto &it : ma) {
			if (it.first >= begin && it.first <= end) erase_idx.emplace(it.first);
		}
		for (auto &it : erase_idx) {
			ma.erase(it);
		}
	}

	ostream& operator<<(ostream &os, const map<int,String> &ma) {
		for (auto &it : ma) {
			os << it.second << ' ';
		}
		return os;
	}

}

#endif