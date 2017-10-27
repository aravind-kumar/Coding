#include <iostream>
#include <vector>
using namespace std;

int findMajority(vector<int> inputArray,int low,int high)
{
   if(low<=high)
   {
      int mid = low+(high-low)/2;
      int leftMaj = findMajority(inputArray,low,mid-1);
      int rightMaj = findMajority(inputArray,mid+1,high);
      int lCount = count(inputArray.begin()+low,intArray.begin()+mid-1,leftMaj);
      int rCount = count(inputArray.begin()+mid+1,intArray.begin()+high,rightMaj);
      
      if(lCount > mid+1)
      {
         return lCount;
      }
      else if(rCount > mid+1)
      {
         return rCount;
      }
      else 
         return -1;
   }
   return -1;
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
   cout<<"\n The majority element is "<<findMajority(inputArray,0,inputArray.length()-1);  
   return 0;
}
