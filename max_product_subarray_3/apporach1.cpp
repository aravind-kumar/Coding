#include <iostream>
#include <numeric>
#include <algorithm>
#include <utility>

int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int maxSum = accumulate(nums.rbegin(),nums.rbegin()+3,1,multiplies<int>());
        int minSum = accumulate(nums.begin(),nums.begin()+2,1,multiplies<int>());
        return max(maxSum,minSum*nums.back());
        
}

int main() {

    vector<int> input;

    return 0;
}
