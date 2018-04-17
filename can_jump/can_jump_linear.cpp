#include <iostream>
#include <vector>
#include <utility>
using namespace std;

 bool canJump(vector<int>& nums) { 

// At every step we find the max range that we can go 
// And keep iterating i till we hit that range or we are at size
// If we are at size we can reach the goal 
        
        int i = 0;
        for(int reach=0;i<nums.size() && i<=reach;++i){
            reach=max(i+nums[i],reach);
        }  
        return i == nums.size();
        
        
        
}
int main() {

   return 0;
}
