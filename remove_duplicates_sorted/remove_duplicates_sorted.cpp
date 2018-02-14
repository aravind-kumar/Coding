#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i=nums.length > 1 ? 1 : 0;
        for(int num : nums) {
            if(num > nums[i-1]){
                nums[i++] = num;
            }
        }
        return i;
                
    }
};

int main()
{

    return 0;
}
