#include <iostream>
#include <vector>

using namespace std;

bool doesSumExsist(vector<int> input,int size,int sum)
{
   if(sum==0)
     return true;
   if(sum > 0 && !size)
     return false;

   return doesSumExsist(input,size-1,sum) 
	  || 
          doesSumExsist(input,size-1,sum-input[size-1]);
}

int main()
{
   int num;
   vector<int> input;
   cout<<"\n Enter the number of elements to in the array";
   cin>>num;
   for(int i=0;i<num;++i)
   {
     int givenNum;
     cin>>givenNum;
     input.push_back(givenNum);
   }
   cout<<"\n Enter the sum to check ";
   cin>>num;
   cout<<"\n Does the sum exsits in the array "<<doesSumExsist(input,input.size(),num); 
   return 0;
}
