#include <iostream>
#include <vector>

using namespace std;

// This is the template for genrating combinations
void generateValidParens(vector<string>& result,string temp,int openCount,int closeCount,int max)
{
   if(temp.length() == max*2) // We check with max*2 because we are given n interms of pairs
      result.push_back(temp);
   else
   {
      if(openCount < max) // At most we can have n open brackets that is with a string length of n we can have n/2 open parens.
        generateValidParens(result,temp+'(',openCount+1,closeCount,max);
      if(openCount > closeCount) //if the count of open Parens > close Count then it means that we can have more open parens.
        generateValidParens(result,temp+')',openCount,closeCount+1,max);
   }
}

vector<string> generateValidParens(int n)
{
   vector<string> validParens;
   string tempString="";
   generateValidParens(validParens,tempString,0,0,n);
   return validParens;
}

int main()
{
   vector<string> validParens;
   int n;
   cout<<"\n Enter the number of pairs for n";
   cin>>n;
   validParens= generateValidParens(n);
   for(auto&& str : validParens)
      cout<<str<<endl;
}
