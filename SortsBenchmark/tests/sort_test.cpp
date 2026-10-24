#include <archbenchs/sort.hpp>

#include <algorithm>
#include <iostream>
#include <vector>

bool check_sort(std::vector<double> data) {
	std::vector<double> expected = data;
	std::sort(expected.begin(), expected.end());

	archbenchs::sorting::parallel_quick_sort(data.data(), data.size());
	return data == expected;
}

int main() {
	if (!check_sort({4.0, 1.0, 3.0, 2.0, 2.0, -1.0})) {
		std::cout << "Small test failed" << std::endl;
		return 1;
	}

	const int64_t size = 250000;
	std::vector<double> data(size);

	for (int64_t i = 0; i < size; i++)
		data[i] = size - i;

	if (!check_sort(data)) {
		std::cout << "Large test failed" << std::endl;
		return 1;
	}

	std::cout << "Sort tests passed" << std::endl;
	return 0;
}
