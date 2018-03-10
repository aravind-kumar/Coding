#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int maxProductSubarray(const vector<int>& nums) { 

     int minProductTillNow = 1;
     int maxProductTillNow = 1;
     int globalMax = nums.front();
      
     auto maxProductComputer = [&] (int num) {
           tie(minProductTillNow,maxProductTillNow) = minmax({num*minProductTillNow,num*maxProductTillNow,num});
           globalMax = max(globalMax,maxProductTillNow);
     };
     for_each(nums.begin(),nums.end(),maxProductComputer);
     return globalMax;
}

int main() {
    vector<int> input = {2,3,-3,4};
    cout<<"\n  the max product of the subarray is "<<maxProductSubarray(input);
    return 0;
}
