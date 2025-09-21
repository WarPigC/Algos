#include <vector>
#include <algorithm>

int LongestSubArray(){

std::vector<int> nums = { 1,2,3,3,2,2 };        // { 4,4,4,2,3,3,4,4,4,4,3 }

int num = 0, count = 1;
int temp = 0;

// find greatest number
num = *std::max_element(nums.begin(), nums.end());

// traverse left
for (int& a : nums) {

    if (a == num) {
        ++temp;
        if (count < temp) {
            count = temp;
        }
    }
    else {
        temp = 0;
    }
}

}