#include <iostream>
#include <vector>

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        
        vector<int> days(flowers.size());
        
        for (int i=0;i<flowers.size();++i) {
            days[flowers[i]-1] = i+1;
        }
        int left=0,right=k+1,res = INT_MAX;
        
        for(int i=0;right<flowers.size();++i) {
            if(days[i]>days[left] && days[i]>days[right]) 
                continue;
                if (i == right) {
                    int ans = max(days[left],days[right]);
                    res = min(res,ans);
                }
                left = i;
                right = i+k+1;
            
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main()
{


   return 0;
}
