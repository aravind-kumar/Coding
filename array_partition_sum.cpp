#include <iostream>
#include <vector>
#include <algoritm>

using namespace std;

// In this question we are asked to maximize the sum of min(a0,b0) + min(a1,b1) ...
// Given an input array we have to form pairs such that we maximize the sum of mini of the numbers;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int sum=0;
        for(int i=0;i<nums.size();i+=2) sum+=nums[i];
        
        return sum;
        
    }
};

int main() {



    return 0;
}
