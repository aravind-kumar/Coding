#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int findSourceIndex(vector<int>& nums) {
        for(int i=nums.size()-1;i>=1;--i) {
            if(nums[i-1]<nums[i])
                return i-1;
        }
        return -1;
    }
    
    int findDestinationIndex(vector<int>& nums,int srcIndex) {
        int ansIndex = -1;
        int src = nums[srcIndex];
        for(int i=srcIndex;i<nums.size();++i) {
            if(nums[i]>src) {
                ansIndex=i;
            }
        }
        return ansIndex;
    }
    
    void reverse(vector<int>& nums,int startIndex) {
        for(int i=startIndex,j=nums.size()-1;i<j;++i,--j){
            swap(nums[i],nums[j]);
        }    
    }
    
    void nextPermutation(vector<int>& nums) {
        
        int srcIndex = findSourceIndex(nums);
        int dstIndex = findDestinationIndex(nums,srcIndex);
        if(srcIndex != -1 && dstIndex != -1) {
            swap(nums[srcIndex],nums[dstIndex]);
            reverse(nums,srcIndex+1);
        }else {
            reverse(nums,0);
        }
    }
};


int main()
{


    return 0;
}
