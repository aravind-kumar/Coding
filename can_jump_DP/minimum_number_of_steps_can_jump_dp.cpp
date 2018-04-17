#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
        vector<int> cache(nums.size(),0);
        
        for(int i=1;i<nums.size();++i) {
            int minValue = INT_MAX;
            for(int j=0;j<i;++j) {
                if(j+nums[j]>=i)
                    minValue = min(minValue,cache[j]);
            }
            cache[i]=minValue != INT_MAX ? minValue+1 : 0;
        }
        
        return cache.back();
        
    }


int main() {



     return 0;
}
