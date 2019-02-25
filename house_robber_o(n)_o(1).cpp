class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        if(nums.size() == 1) return nums[0];
        int firstDay = nums[0];
        int secondDay = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();++i) {
            int currMax = max(firstDay+nums[i],secondDay);
            firstDay = secondDay;
            secondDay = currMax;
            
        }
        
        return max(firstDay,secondDay);
    }
};

//FirstDay secondDay represents the max amount that the robber can rob on n-1(second) and n-2(first) days
//The robber is aloweed to take currMax(max for the current House) = max(first+nums[i] , second)
// Once this is completed and we proceed for the next iteration the firstDay becomes the secondDay and the secondDay is the currentMax.
