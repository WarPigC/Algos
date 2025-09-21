#include <iostream>
#include <vector>

int kadanes(std::vector<int> &nums) {
    
    int max = nums[0];
    int cur = 0;

    for (int i : nums){
        cur = std::max(cur,0);
        cur += i;
        max = std::max(cur,max);
    } 
    return max;
}

//                                    FOR CIRCULAR ARRAYS
/*
        int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }

*/

int main(){
    std::vector<int> vec {5,4,-1,7,8};
    std::cout << kadanes(vec);
}
