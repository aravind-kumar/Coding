#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int FindMajority(vector<int> inputVector)
{
   int majority=0,count=0;
   for(auto num : inputVector) {
      if(num == majority) 
           count++;
      else if (majority==0) {
           majority = num;
           count=1;
      }
      else 
           count--; 
   }
   return majority;
}
int main()
{
   int num;
   vector<int> inputVector;
   cout<<"\n Enter the number of elements";
   cin>>num;
   for(int i=0;i<num;++i)
   {
      int givenInput;
      cin>>givenInput;
      inputVector.push_back(givenInput);
   }
   cout<<"\n The majority element is "<<FindMajority(inputVector);
   return 0;
}
