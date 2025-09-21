#include <array>
#include <iostream>

inline void LinearSearch(const std::array<int,10>& ar,const int key) {
	
	std::cout << "key: " << key << '\n';

	for (int i : ar) {
		if (i == key) {
			std::cout << "Linear: Key found at " << *(ar.begin() + i) << "\n\n";
			return;
		}
	}
	std::cout << "Key not found\n";
}

inline void BinarySearch(const std::array<int,10>& ar,const int key) {
	
	std::cout << "key: " << key << '\n';

	int low = 0;
	int high = ar.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (ar[mid] == key) {
			std::cout << "Binary: Key found at " << mid << "\n\n";
			return;
		}
		else if (key > ar[mid]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
}


inline void InterpolationSearch(const std::array<int,10>& ar,const int key) {

	std::cout << "key: " << key << '\n';

	int low = 0;
	int high = ar.size() - 1;

	while (low <= high && ar[low] <= key && ar[high] >= key) {
		
		int pos { (((high - low) / (ar[high] - ar[low])) * (key - ar[low])) + low};

		if (ar[pos] == key) {
			std::cout << "Interpolation: Key found at " << pos << "\n\n";
			return;
		}
		else if (ar[pos] < key) {
			high = pos - 1;
		}
		else {
			low = pos + 1;
		}
	}
}

int main() {
	
	std::array<int, 10> ar { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	LinearSearch(ar, rand() % 10);

	BinarySearch(ar, rand() % 10);

	InterpolationSearch(ar, rand() % 10);

}
