#include <iostream>
#include <unordered_set>

bool isWordBreakable(unordered_set<string> map,string input)
{
   vector<bool> result(input.size(),0);
   result[result.size()-1] = 1;
   string subString;
   for(int i=input.size()-1; i>=0;--i)
   {
      for(int j=i;j<n;++j)
      {
         subString += input[j];
         result[i] = input.count(subString);
         if(result[j+1])
	   break;
      } 

   }
   return result[0];

}

int main()
{
   
   return 0;
}
