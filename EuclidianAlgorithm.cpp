#include <iostream>

inline int EuclideanAlgorithm(int a, int b) {
    return (b == 0) ? a : EuclideanAlgorithm(b, a % b);

    // used to find the GCD (Greatest common divisor) or HCF of 2 numbers
    // works by finding remainders 
    
    /* example: input-> a = 24 and b = 36
     a, b
    24, 36
    36, 24
    24, 12
    12, 0

    returns 12
    
    */
}


int main(){

  std::cout << EuclideanAlgorithm(24,36);

}
