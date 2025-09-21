#include <iostream>
#include <vector>

/*
 * STEPS TO MAKE A DIFF ARRAY:
 
 * 'arr' is the given array. make a new array with n + 2 size since we're working from index 1 to n + 1 (shift indices right once (important later on))
 *  
 *  we're given a set of queries with a range 'l' and 'r' [line 6]
 *
 *  now, in diff array add any arbitrary value (here 1) in index 'l' and subtract the value from 'r' index [line 9]
 *
 *  now the purpose of taking n + 2 is to add i-1th index to ith index in diff array, starting with 1 (we don't count 0), also seen in counting sort
 *  so i-1th index (0) added to ith (1) and then (1) to (2) and so on.  [line 16]
 *
 *  now add every element's updated value to 'arr'. do note that diff array is indexed 1 index ahead of 'arr' [line 18]
 *
 *  queries processing completed
 * */

int main(){

    std::vector<int> arr {1, 1, 1, 1, 1}, diffArr(arr.size() + 2, 0);
    int l, r, q;                                    // NOTE: 0 <= l <= r <= n - 1
    std::cin >> q;

    while (q){
        std::cin >> l >> r;
        diffArr[l + 1] += 1;
        diffArr[r + 2] -= 1;
        --q;
    }

    for(int i = 1; i < arr.size() + 1; ++i){
        diffArr[i] += diffArr[i - 1];
        arr[i - 1] += diffArr[i];
    }

    for(int i : arr){
        std::cout << i << " ";
    }
}
/*  test case ; answer = 2 3 3 2 2
 
3
0 2
1 2
3 4

*/
