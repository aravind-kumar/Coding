#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

typedef vector<vector<int>> lcsArray;
int LCS(tring s1,string s2)
{
  lcsArray input;
  Initiliaze(input);
  for(int i=1;i<=s1.length();++i)
  { 
       for(int j=1;j<=s2.lenght();++j)
       {
           if(s1[i-1] == s2[j-1])
             input[i][j]=input[i-1][j-1];
           else
             input[i][j]=max(input[i-1][j],input[i][j-1]); 
       }
  }
  return input[s1.length()-1][s2.length()-1];
}

int main()
{
   return 0;
}

