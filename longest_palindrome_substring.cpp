#include <iostream>
#include <string>

using namespace std;


//Find the longest substring, we use brute force approach to find the longest palindrome substring.
//We assume that the first position is that start position and try to the longest substring with that.
//There are 2 possibilites that the string is odd length and the string is of even length.
//We have to consider both cases and find the max of them


class Solution {
public:
    string longestPalindrome(string s) {
        string max = "";
        
        for(int i=0;i<s.length();++i) {
            string evenString = getMaxSubstring(s,i,i);
            string oddString = getMaxSubstring(s,i,i+1);
            if(evenString.length() > max.length()) max = evenString;
            if(oddString.length() > max.length()) max = oddString;
        }
        
        return max;
    }
    
    string getMaxSubstring(string input,int start,int end) {
        for(;0<=start && end<input.length();--start,++end) {
            if(input[start] != input[end]) break;
        }
        return input.substr(start+1,end-start-1);
    }
};


int main() {



  return 0;
}
