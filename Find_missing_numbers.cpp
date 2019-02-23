// Given that the array of numbers from 0 to n-1 find all the missing numbers in the array, note that the array can have duplicates in them
// We see the array as a hashmap where the index are unique and we travese the array using the values
// for every value visited we mark it using a sentinal value to say that we have visited it using -1 since all the numbers are from 0-n
/// Then we iterate the array again this time we check which ones are not -1 and then return them as a an array.
// The worst case time complexity would be o(3n) , this can be reduced to o(2n) 
// Will write the code for that as well.
class Solution {
public:
    void visitNodes(vector<int>& input,int index) {
        while(index < input.size() && input[index] != -1) {
            int temp = input[index]-1;
            input[index] = -1;
            index = temp;
            
        }
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int i = 0;
        while(i<nums.size()) {
            if(nums[i] != -1) {
                visitNodes(nums,nums[i]-1);
            }
            ++i;
        }
        
        for(int i=0;i<nums.size();++i) {
            if(nums[i] != -1) 
                result.push_back(i+1);
        }
        return result;
        
    }
};
