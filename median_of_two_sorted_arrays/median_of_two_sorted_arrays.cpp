#include <iostream>
#include <vector>
#include <algorithms>

class Solution {
public:
    int findMax(int i,int j,vector<int>& nums1,vector<int>& nums2) {
        int minNum;
        if(i==0) {
            minNum = nums2[j-1];
        } else if (j==0){
            minNum = nums1[i-1];
        } else {
            return max(nums1[i-1],nums2[j-1]);
        }
        return minNum;
    }
    
    int findMin(int i,int j,vector<int>& nums1,vector<int>& nums2) {
        int maxNum;
        if(i==nums1.size()) {
            maxNum = nums2[j];
        } else if (j==nums2.size()){
            maxNum = nums1[i];
        } else {
            return min(nums1[i],nums2[j]);
        }
        return maxNum;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();   
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int minNum = 0 , maxNum = nums1.size();
        int i,j;
        while(minNum<=maxNum) {
            i= minNum + (maxNum-minNum)/2;
            j = ((nums1.size() + nums2.size() + 1)/2) - i;
            if(i>0 && j<n && nums1[i-1]>nums2[j]) {
                    maxNum = i-1;
            } else if (j>0 && i<m &&  nums2[j-1]>nums1[i]) {
                    minNum = i+1;
            } else {
                break;
            }
        }
        
        int minI = findMax(i,j,nums1,nums2);
        int minJ = findMin(i,j,nums1,nums2);

        
        if((m+n) % 2 == 1) {
            return minI;
        } else {
            return (minI+minJ)/2.0;
        }    
    }
};

int main() {



}
