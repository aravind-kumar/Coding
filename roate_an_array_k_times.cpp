class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty() || k < 0 || k%nums.size() == 0) return;
        k = k%nums.size();
        
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
    }
};
