#ifndef _RADIX_SORT_H
#define _RADIX_SORT_H

#include <queue>
#include <vector>

// Radix sort function using base-10 funciton -  works up to 10e8
template <typename T, typename Container = std::vector<T>>
void radix_sort(Container &array) {
	const unsigned BASE = 10;
	std::queue<int> bucket[BASE];
	// Finding maximum element in vector
	T max = *std::max_element(array.begin(), array.end());
	// Sorting by least significant digit
	for (unsigned power = 1; max != 0; max /= BASE, power *= 10) {
		// Version I of assigning vector to buckets
		for (unsigned i = 0; i < array.size(); ++i) {
			//int bucket_num = abs((array.at(i) / power) % BASE); // take absolute value for negative nubers
			unsigned bucket_num = (array.at(i) / power) % BASE; // Not passing nevative numbers so absolute value not needed
			bucket[bucket_num].push(array.at(i)); // Put vector into buckets O(1)
		}
		// Version II assigning vector to buckets
		//for (unsigned long i : array) {
		//	//int bucket_num = abs((array.at(i) / power) % BASE); // take absolute value for negative nubers
		//	unsigned bucket_num = (i / power) % BASE; // Not passing nevative numbers so absolute value not needed
		//	bucket[bucket_num].push(i); // Put vector into buckets O(1)
		//}
		// clear vector
		array.clear();
		// put buckets into vector
		for (unsigned i = 0; i < BASE; ++i) {
			while (!bucket[i].empty()) {
				array.push_back(bucket[i].front());
				bucket[i].pop();
			}
		}
	}
}

#endif // !_RADIX_SORT_H

