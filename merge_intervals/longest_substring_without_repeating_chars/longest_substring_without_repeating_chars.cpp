#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(256,-1);
        int longest=0,start=0;
        for(int i=0;i<s.length();++i) {
            start=max(start,charIndex.at(s[i])+1);
            charIndex[s[i]]=i;
            longest = max(longest,i-start+1);
        }
        return longest;
    }
};

using namespace std;

int main() {

    Solution s;
    string input;
    cout<<"\n Enter the input string";
    cin>>input;
    cout<<"The longest substring is "<<lengthOfLongestSubstring(s);
    return 0;    
}
