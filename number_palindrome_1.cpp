#include <iostream>

using namespace std;


class Solution {
public:
    int len(int x) {
        int count = 0;
        while(x!=0) {
            ++count;
            x=x/10;
        }
        return count;
    }
    
    int getNthNumber(int x,int position,int len) {
        int ans = -1;
        for(int start=len;start>=position;--start) {
            ans = x%10;
            x=x/10;
        }
        return ans;
    }
    
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        int l = len(x);
        
        
        for(int i=1,j=l; i<=j ; ++i,--j) {
            int xVal = getNthNumber(x,i,l);
            int yVal = getNthNumber(x,j,l);
            if( xVal != -1 && yVal != -1 && xVal != yVal)
                return false;
        }
        
        return true;
        
    }
};


int main() {



  return 0;
}
