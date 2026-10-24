#include <archbenchs/sort.hpp>

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
	int64_t size = 1000000;
	int threads = 4;
	int repeats = 5;

	if (argc > 1)
		size = std::atoll(argv[1]);
	if (argc > 2)
		threads = std::atoi(argv[2]);
	if (argc > 3)
		repeats = std::atoi(argv[3]);

	archbenchs::ExecutionOptions options;
	options.threads = threads;

	std::srand(42);
	std::vector<double> source(size);
	for (int64_t i = 0; i < size; i++)
		source[i] = std::rand();

	long long total_time = 0;

	for (int i = 0; i < repeats; i++) {
		std::vector<double> data = source;

		auto start = std::chrono::high_resolution_clock::now();
		archbenchs::sorting::parallel_quick_sort(data.data(), data.size(), options);
		auto end = std::chrono::high_resolution_clock::now();

		total_time += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

		if (!std::is_sorted(data.begin(), data.end())) {
			std::cout << "Sorting failed" << std::endl;
			return 1;
		}
	}

	double average_time = total_time / (double)repeats;

	std::cout << "Size: " << size << std::endl;
	std::cout << "Threads: " << threads << std::endl;
	std::cout << "Average time: " << average_time << " ms" << std::endl;

	return 0;
}
