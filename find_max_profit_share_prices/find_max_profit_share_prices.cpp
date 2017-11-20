#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int findMaxProfit(vector<int> givenPrices)
{  
   int max=0;
   int profit=0;
   int min=givenPrices[0];
   for(int i=0;i<givenPrices.size();++i)
   {
     if(givenPrices[i]<min)
       min = givenPrices[i];
     if(givenPrices[i]>max)
       max = givenPrices[i];
     if(max-min > profit)
       profit = max-min;
   }
   cout<<"\n the max is "<<max;
   cout<<"\n the min is "<<min;
   return profit;
}

int main()
{
   int numOfElement;
   vector<int> inputVector;
   cout<<"\n Enter the number of elements";
   cin>>numOfElement;
   cout<<"\n Enter the elements";
   for(int i=0;i<numOfElement;++i)
   {
      int input;
      cout<<"\n Enter the input";
      cin>>input; 
      inputVector.push_back(input); 
   }
   cout<<"\n The maximum profit is" <<findMaxProfit(inputVector);
   return 0;
}
