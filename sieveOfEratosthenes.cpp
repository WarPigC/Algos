/*								Sieve of Eratosthenes
 * 
 * this algorithm is used to sift all prime numbers in a given range (0 - n) with O(N) space 
 * and O(N log log N) time. It is useful to get all primes to process or use them later.
*/


#include <iostream>
#include <vector>


void sifter(int n){

	std::vector<bool> numbers(n + 1, true);
	numbers[0] = numbers[1] = false;		// 0 and 1 case

	for(int i = 2; i <= n; ++i){
		if ((numbers[i]) && ((long long) (i * i) <= n)){		// check incase i^2 is out of bounds or number is composite
			for(int j = i * i; j <= n; j += i){				// starting from i^2 we go through all multiples of i.
				numbers[j] = false;							// i^2 is an optimization of the naive implementation (going from i to n) to reduce checks
			}
		}
	}

	for(int i = 0; i <= n; ++i){								// printing all primes
		if (numbers[i]) std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main(){

	sifter(100);


	return 0;
}
