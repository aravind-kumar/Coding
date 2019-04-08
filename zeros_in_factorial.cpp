class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;        
        while(n>0) {
            int num = n/5;
            ans+=num;
            n=num;      
        }
        return ans;
    }
};
