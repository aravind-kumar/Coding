#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

int FindMajority(vector<int> inputArray)
{
   if(inputArray.size()==1)
   {
      return inputArray[0];
   } 
   else 
   {
      int mid = inputArray.size()/2;
      vector<int> left(inputArray.begin(),inputArray.begin()+mid);
      vector<int> right(inputArray.begin()+mid,inputArray.end());
      
      int leftMajority = FindMajority(left);
      int rightMajority = FindMajority(right);
     
      if(leftMajority == rightMajority)
      { 
          return leftMajority;
      }
      int lCount = count(left.begin(),left.end(),leftMajority);
      int rCount = count(right.begin(),right.end(),rightMajority);
      
      if(lCount >= mid)
      {
         return leftMajority;
      }
      else if(rCount>= mid)
      {
         return rightMajority;
      }
      return -1;
   }
}

int main()
{
   int n;
   vector<int> input;
   cout<<"\n Enter the number of elements";
   cin>>n;
   for(int i=0;i<n;++i)
   {
     int givenInput;
     cin>>givenInput;      
     input.push_back(givenInput);
   } 
   cout<<"\n The majority element is "<<FindMajority(input);
   return 0;
}
