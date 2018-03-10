#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>

// Find the index to whose left sum == sum of right elements

using namespace std;

int pivotIndex(vector<int> nums) {
    int sum = accumulate(nums.begin(),nums.end(),0,plus<int>());
    int presentSum = 0;
    for(int i=0;i<nums.size();++i) {
        if(presentSum == sum-nums[i]) return i;
        presentSum+=nums[i];
        sum-=nums[i];    
    }
    return -1;
}

int main() {

    vector<int> input={1, 7, 3, 6, 5, 6};
    cout<<"\n The pivot index is "<<pivotIndex(input);
    return 0;
}
