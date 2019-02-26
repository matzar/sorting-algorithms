#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H

#include <vector>
#include <algorithm>

template <typename T, typename Container = std::vector<T>>
void quick_sort(Container &array, long left, long right) {
	long i = left;
	long j = right;
	unsigned long pivot = array.at((unsigned long)((left + right) / 2));
	
	while (i <= j) {
		while (array.at(i) < pivot) ++i;
		while (array.at(j) > pivot) --j;
		if (i <= j) {
			std::swap(array.at(i), array.at(j));
			++i;
			--j;
		}
	}
	// check if we need to keep sorting
	if (left < i) quick_sort<T>(array, left, j);
	if (j < right) quick_sort<T>(array, i, right);
}

#endif // !_QUICK_SORT_H

