#include <iostream>
#include <vector>

using namespace std;

int findMaxIndex(vector<int>nums,int i,int j,int k) {
    
    int iVal = i >= 0 && i < nums.size() ? nums[i] : INT_MIN;
    int jVal = j >= 0 && j < nums.size() ? nums[j] : INT_MIN;
    int kVal = k >= 0 && k < nums.size() ? nums[k] : INT_MIN;
     
    int maxVal = max(iVal,max(jVal,kVal));
    if (maxVal == iVal) return i;
    else if (maxVal == jVal) return j;
    else return k;
}

void sortValleyPeak(vector<int>& nums) {
   for(int i=1;i<nums.size();i+=2) {
      int maxIndex = findMaxIndex(nums,i-1,i,i+1);
      if (i != maxIndex)
          swap(nums[maxIndex],nums[i]); 
   }
}




int main() {

    vector<int> input = {5,3,1,2,3};
    sortValleyPeak(input);
    for(auto&& num : input) {
        cout<<num<<" ";  
    }
    return 0;
}

