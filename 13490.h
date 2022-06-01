//#include "Main.cpp"
/*#if __cplusplus < 201103L
#error Sorry, but this partial-judged problem requires at least C++11.
#endif*/

template<typename Iterator>
Iterator k_unique(Iterator l, Iterator r, int x) {
	if (l == r) return r;
	int cnt = 1;
	Iterator cur = l;
	while (++l != r) {
		if (*l == *cur) cnt++;
		else cnt = 1;
		if (*l != *cur || cnt <= x) *(++cur) = *l;
	}
	return ++cur;
}

