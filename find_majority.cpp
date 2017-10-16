#include <iostream>
#include <vector>

using namespace std;
// Minor bug have to fix
int FindMajority(vector<int> inputArray,int low,int high)
{
   if(low<=high)
   {
      int mid = low+(high-low)/2;
      int leftMajority = FindMajority(inputArray,low,mid-1);
      int rightMajority = FindMajority(inputArray,mid+1,high);
      
      if(leftMajority == rightMajority)
      { 
          return leftMajority;
      }
      int lCount = count(inputArray.begin(),inputArray.end(),leftMajority);
      int rCount = count(inputArray.begin(),inputArray.end(),rightMajority);

      if(lCount >= mid+1)
      {
         return leftMajority;
      }
      else if(rCount>= mid+1)
      {
         return rightMajority;
      }
      return -1;
   }
   return -1;
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
   cout<<"\n The majority element is "<<FindMajority(input,0,n-1);
   return 0;
}
