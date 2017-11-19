#include <iostream>
#include <unordered_set>




bool isWordBreakable(unordered_set<string> map,string input)
{
   vector<bool> result(s.size()+1);
   result[s.size()] = 1;
  
   for(int i=s.size()-1; i>=0;--i)
   {
      string subString;
      for(int j=i;j<s.size();++j)
      {
         subString += s[j];
         result[i] = find(wordDict.begin(),wordDict.end(),subString) != wordDict.end();
         if(result[i] && result[j+1])
           break;
      }

   }
   return result[0];
}

int main()
{
   
   return 0;
}
