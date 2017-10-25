#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

int find_max_profit_for_complete(vector<int> input)
{
   int profit = 0;

   assert(input.size());

   for(int i=0,j=i+1;i<input.size()-1;++i,++j)
   {
      if(input[j] > input[i]) 
          profit+=input[j]-input[i];
   }
   return profit;
   
}

int main()
{
   int n;
   vector<int> inputArray;
   cout<<"\n Enter the number of elements";
   cin>>n;
   cout<<"\n Enter the elements";
   for(int i=0;i<n;++i)
   {
      int input;
      cin>>input;
      inputArray.push_back(input);
   }
   cout<<"\n The maximum profit is "<<find_max_profit_for_complete(inputArray);
   return 0;
}
