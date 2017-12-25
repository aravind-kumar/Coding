#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestString(string s)
{
   vector<int> charIndex(256,-1);
   int longest = 0,start=0;
   for(int i=0;i<s.length();++i)
   {
      start = max(start,charIndex.at(s[i])+1);      
      charIndex[s[i]] = i;
      longest = max(longest,start-i+1);
   }
   return longest;
}

int main()
{
   string s;
   cout<<"\n Enter the input string";
   cin>>s;
   cout<<"\n The length of longest string is"<<longestString(s);
   return 0;
}
