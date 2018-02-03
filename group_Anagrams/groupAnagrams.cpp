#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
   unordered_map<string,vector<string>> groupAnagrams;

   for(auto&& str : strs) {
       vector<int> charCount(26,0);
       for(int i=str.length()-1;i>=0;--i){
           ++charCount[str[i]-'a'];
       }
       string key="";
       for(int i=charCount.size()-1;i>=0;--i){
           key+=to_string(charCount[i]);
       }
       groupAnagrams[key].push_back(str);
   }
   vector<vector<string>> ans;
   for(auto&& pairs : groupAnagrams) {
       ans.push_back(pairs.second);
   }
   return ans;
}

int main()
{
   int num;
   vector<string> input;
   cout<<"\n Enter the number of inputs";
   cin>>num;
   cout<<"\n Enter the inputs";
   for(int i=0;i<num;++i) {
       string inputStr; 
       cout<<"\n Enter input";
       cin>>inputStr;
       input.push_back(inputStr);
   }
   vector<vector<string>> ans = groupAnagrams(input);
   for(auto&& strs : ans) {
      for(auto&& str : strs) {
         cout<<str; 
      } 
   }
   

    return 0;
}
