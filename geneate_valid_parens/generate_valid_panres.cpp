#include <iostream>
#include <vector>

using namespace std;

void generateValidParens(vector<string>& result,string temp,int openCount,int closeCount,int max)
{
   if(temp.length() == max*2)
      result.push_back(temp);
   else
   {
      if(openCount < max)
        generateValidParens(result,temp+'(',openCount+1,closeCount,max);
      if(openCount > closeCount)
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
