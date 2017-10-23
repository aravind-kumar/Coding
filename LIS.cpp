#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <assert.h>

using namespace std;

int LIS(vector<int> input)
{
   vector<int> lis(input.size(),1);
   for(int i=1;i<=input.size();++i)
   {
       if(input[i] > input[i-1])
       {
         int maxTillNow = *(max_element(lis.begin(),lis.begin()+i));
         lis[i]=maxTillNow+1;
       }
   }
   return lis.back(); 
}

int main()
{
  vector<int> input={10, 22, 9, 33, 21, 50, 41, 60};
  cout<<LIS(input);
}
