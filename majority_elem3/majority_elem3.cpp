#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     
        typedef pair<int,int> numCount;
        numCount num1,num2;
        num1 = num2 = {-1,0};
        
        for(int i=0;i<nums.size();i++) {
            if(num1.first == nums[i]) {
                num1.second++;
            } else if(num2.first == nums[i]) {
                num2.second++;
            } else if(num1.second == 0 ){
                num1.first = nums[i];
                num1.second = 1;
            } else if(num2.second == 0 ) {
                num2.first = nums[i];
                num2.second = 1;
            } else {
                num1.second--;
                num2.second--;
            }

        }
        
        int count1=0,count2=0;
        for(auto&& num : nums) {
            if(num == num1.first) ++count1;
            else if (num == num2.first) ++count2;
        }
        
        vector<int> ans;
        cout<<num1.first<<endl;
        cout<<num2.first<<endl;
        if(!nums.empty()) {
            
            if(count1 > (nums.size()/3)) ans.push_back(num1.first);
     
            if(count2 > (nums.size()/3)) ans.push_back(num2.first);    
            
        }

        return ans;
    }
};


int main() {




}
