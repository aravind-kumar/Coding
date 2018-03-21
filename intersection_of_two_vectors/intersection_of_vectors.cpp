#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
     if(nums2.size() < nums1.size())
         return intersect(nums2,nums1);
     vector<int> ans;
     unordered_map<int,int> numFreq;
     
     for(int num : nums1) {
         if(numFreq.find(num) != numFreq.end()) {
             ++numFreq[num];
         } else {
             numFreq[num] = 1;
         }
     }
     
     for(int num : nums2) {
         auto it = numFreq.find(num);    
         if(it != numFreq.end() && it->second > 0) {
             ans.push_back(num);
             --numFreq[num];
         } 
     }
     
     return ans;
}

int main() {



    return 0;
}
