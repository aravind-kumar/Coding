#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        vector<bool> ans(s.length()+1,false);
        ans[0]=true;
        
        for(int i=0;i<s.length();++i) {
            for(int j=0;j<=i;++j) {
                if(ans[j]) {
                    string word = s.substr(j,i-j+1);
                    if(wordSet.find(word) != wordSet.end()) {
                        ans[i+1]=true; //Why i+1 ?
                    }
                }
            }
        }
        return ans[s.length()];
    }
};

int main() {



    return 0;
}
