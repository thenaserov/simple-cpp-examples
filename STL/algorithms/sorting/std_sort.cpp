#include <algorithm>
#include <iostream>

int main() {
	int arr[] = {3, 5, 1, 2, 4};

	// Sort the array in ascending order
	std::sort(std::begin(arr), std::end(arr));

	// Print the sorted array
	for (int i : arr) {
		std::cout << i << " ";
	}
	return 0;
}
