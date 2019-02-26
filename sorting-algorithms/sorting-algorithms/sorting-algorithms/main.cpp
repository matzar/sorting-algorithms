// Project made by Mateusz Zaremba based on Adam Sampson's solution
// Architectures and Performance: Basic Benchmarking lab exercise
// Adam Sampson <a.sampson@abertay.ac.uk>
// Mateusz Zaremba <1502616@abertay.ac.uk>

#include <chrono>
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <ctime>
#include "radix_sort.h"
#include "quick_sort.h"

// Import things we need from the standard library
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::cout;
using std::endl;
using std::this_thread::sleep_for;

// Define the alias "the_clock" for the clock type we're going to use.
// (You can change this to make the code below use a different clock.)
typedef std::chrono::steady_clock the_clock;
// functions declarations
void random_array(unsigned long length);
std::vector<unsigned long> input;

int main(int argc, char *argv[]) {

	std::ofstream outputFile("results_sorted.csv");
	// N must be N <= 10e8 using x86 solution platform
	unsigned long N = 100000000;

	// QUICK SORT
	for (unsigned long i = 10; i <= N; i *= 10) {
		// generate vector with random numbers
		//input.reserve(i);
		//random_array(i);
		std::vector<unsigned long> input = { 10, 8, 7, 5, 3, 4, 2, 1, 0 };

		// Start timing
		the_clock::time_point start = the_clock::now();
		// Calling sorting functions
		quick_sort<unsigned long>(input, 0, input.size() - 1);
		// Stop timing
		the_clock::time_point end = the_clock::now();
		// Compute the difference between the two times in milliseconds
		auto time_taken = duration_cast<milliseconds>(end - start).count();

		cout << endl << "Quicksort: it took " << time_taken << " ms to sort " << i << " items" << endl;
		outputFile << "Quicksort: T " << time_taken << " N " << i << endl;
		//cout << endl << endl;
		//for (int i : input) cout << i << " ";	// development function: displa sorted array to see if algorithm is working
		input.clear();
	}

	// RADIX SORT
	// N must be N <= 10e8 using x86 solution platform
	for (unsigned long i = 10; i <= N; i *= 10) {
		// generate vector with random numbers
		input.reserve(i);
		random_array(i);

		// Start timing
		the_clock::time_point start = the_clock::now();
		// Calling sorting functions
		radix_sort<long long>(input);
		// Stop timing
		the_clock::time_point end = the_clock::now();
		// Compute the difference between the two times in milliseconds
		auto time_taken = duration_cast<milliseconds>(end - start).count();

		cout << endl << "Radix sort: it took " << time_taken << " ms to sort " << i << " items" << endl;
		outputFile << "Radix sort: T " << time_taken << " N " << i << endl;
		//cout << endl << endl;
		//for (int i : input) cout << i << " ";	// development function: displa sorted array to see if algorithm is working
		input.clear();
	}

	// RADIX SORT
	// N must be N <= 10e8 using x86 solution platform
	for (unsigned long i = 10; i <= N; i *= 10) {
		// generate vector with random numbers
		input.reserve(i);
		random_array(i);

		// Start timing
		the_clock::time_point start = the_clock::now();
		// Calling sorting functions
		std::sort(input.begin(), input.end());
		// Stop timing
		the_clock::time_point end = the_clock::now();
		// Compute the difference between the two times in milliseconds
		auto time_taken = duration_cast<milliseconds>(end - start).count();

		cout << endl << "std::sort: it took " << time_taken << " ms to sort " << i << " items" << endl;
		outputFile << "std::sort: T " << time_taken << " N " << i << endl;
		//cout << endl << endl;
		//for (int i : input) cout << i << " ";	// development function: displa sorted array to see if algorithm is working
		input.clear();
	}
	outputFile.close();

	cout << endl << "Press enter...";
	std::cin.get();

	return 0;
}
// Generate random array to sort of N length
void random_array(unsigned long length) {
	long divider = length / 100; // For displaying loading funciton
	cout << endl;
	for (unsigned long i = 0; i < length; ++i) {
		// Loading function
		// --- Start ---
		for (int j = 1; j < 100; ++j) {
			if (j == (double)i / divider) {
				//system("cls");
				cout << "Loading: " << j << endl;
			}
		}
		// --- End ---
		//input.push_back((rand() % length) + 1);		// create array with random numbers
		input.push_back(i);							// create sorted array
	}
}
