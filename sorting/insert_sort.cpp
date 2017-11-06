#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void PrintVector(vector<int>const& input) 
{
   for(auto && elem : input)
   {
      cout<<elem;
   }
}

void InsertSort(vector<int>& input)
{
  for(int i=1;i<input.size();++i)
  {
      int key = input[i];
      int j=i-1;
      while(j>=0 &&  key<input[j])
      {
          --j;
      }
      input.erase((input.begin())+(i));
      input.insert((input.begin())+(j+1),key);
  } 
}
 
int main()
{   
   unsigned int numOfInputs;
   vector<int> inputVector;
   cout<<"\n Enter the number of input ";
   cin>>numOfInputs;
   for(int i =0; i<numOfInputs;++i)
   {
      unsigned int input;
      cout<<"\n Enter the "<<i+1<<" input";
      cin>>input;
      inputVector.push_back(input);
   } 
   InsertSort(inputVector);
   cout<<"\n Sorted Vector is ";
   PrintVector(inputVector); 
   return 0;
}
