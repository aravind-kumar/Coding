#include <iostream>
#include <vector>
int findDuplicate(vector<int>& nums) {
        if(nums.size()){
            int slow = nums[0];
            int fast = nums[nums[0]];
            
            while(slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            
            fast = 0;
            while(slow != fast) {
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
        return -1;
        
    }

int main() {


    return 0;
}
