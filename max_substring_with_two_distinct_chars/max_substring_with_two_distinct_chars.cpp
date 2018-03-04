#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int> sMap;
        int start=0,end=0,maxLen=INT_MIN,targetCount = 0;
        
        while(end<s.length()) {
            
            if (sMap[s[end]] == 0) {
                ++targetCount;
            }
            sMap[s[end]]++;
            
            while(targetCount > 2 && start < s.length()) {
                sMap[s[start]]--;
                if (sMap[s[start]] == 0) {
                    --targetCount;
                }
                ++start;
            }
            maxLen = max(maxLen,end-start+1);
            ++end;
        }
        return maxLen == INT_MIN ? 0 : maxLen;
        
    }
};

int main() {


    return 0;
}
