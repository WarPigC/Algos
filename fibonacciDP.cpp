#include <iostream>
#include <unordered_map>
#include <chrono>
using namespace std::chrono;

std::unordered_map<int, int> map{};


inline int fib(int i){
	std::cout << i;
	if (i <= 1){
		return i;
	}
	else if (map[i]) {
		return map[i];
	}
	else{
		map[i] = fib(i - 1) + fib(i - 2);
		return map[i];
	}
}

inline int fibUnop(int i){
	if (i <= 1) return i;
	std::cout << i;
	return fibUnop(i - 1) + fibUnop(i - 2);
}


int main(){
	// save time1
	auto time = high_resolution_clock::now();

	// execute
	fib(100);

	// calculate time 
	duration<double> t2 = high_resolution_clock::now() - time;
	std::cout << std::endl << "\ntime for execution: " << t2.count();

	return 0;
}

