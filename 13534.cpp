#include <iostream>
#include "13534.h"

void qsort (void* base, size_t num, size_t size, int (*compar)(const void*, const void*)) {
    std::cout << "Please don't cheat.\n";
}
template <class RandomAccessIterator>
void sort (RandomAccessIterator first, RandomAccessIterator last) {
    std::cout << "Please don't cheat.\n";
}
template <class RandomAccessIterator, class Compare>
void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    std::cout << "Please don't cheat.\n";
}

int main() {
    solve();
    return 0;
}
