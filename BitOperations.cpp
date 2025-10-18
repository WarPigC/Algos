#include <iostream>


// 			builtin gcc functions for bit operations


// 			append 'l' or 'll' for long and long long inputs respectively
// 			__builtin_ffsl and __builtin_ffsll

int main(){

	// __builtin_ffs 
	
	// Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.  

	std::cout << __builtin_ffs(10) << std::endl;	 // 1010 so 2
	std::cout << __builtin_ffs(11) << std::endl; 	 // 1011 so 1
	std::cout << __builtin_ffs(16) << std::endl;	 // 10000 so 5
	
	// __builtin_clz
	
	// Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined.  

	std::cout << __builtin_clz(11) << std::endl;  // 28
	std::cout << __builtin_clz(16) << std::endl;  // 27

	// __builtin_ctz

	// Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.  

	std::cout << __builtin_ctz(11) << std::endl;  	// 0
	std::cout << __builtin_ctz(16) << std::endl;  	// 4

	// __builtin_popcount
	
	// Returns the number of 1-bits in x.  
	
	std::cout << __builtin_popcount(16) << std::endl;		// 1
	std::cout << __builtin_popcount(15) << std::endl;		// 4

	// __builtin_parity
	
	// Returns the parity of x, i.e. the number of 1-bits in x modulo 2.  

	std::cout << __builtin_parity(10) << std::endl;		// 1010 so 0
	std::cout << __builtin_parity(11) << std::endl;		// 1011 so 1

	return 0;
}
