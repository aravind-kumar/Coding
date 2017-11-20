#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

void hooresPartition(vector<int>& input,int partitionElement)
{
      if(find(input.begin(),input.end(),partitionElement) != input.end())
      {
         int i=0;
         int j=input.size()-1;
         while(i<j)
         {
            while(input[j] > partitionElement) --j;
            while(input[i] < partitionElement) ++i;
            if(input[i]> input[j]) swap(input[i],input[j]);  
         }
      }
}

void printArray(vector<int> inputVector)
{
   for(auto&& element : inputVector)
   {
      cout<<element;
   }
}
int main()
{
   int n,paritionElement;
   vector<int> inputVector;
   cout<<"\n Enter the number of input";
   cin>>n;
   cout<<"\n Enter the input";
   for(int i=0;i<n;++i)
   {
       int givenInput;
       cin>>givenInput;
       inputVector.push_back(givenInput);
   }
   cout<<"\n Enter the partition Element";
   cin>>paritionElement;
   hooresPartition(inputVector,paritionElement);
   printArray(inputVector);
   return 0;
}
