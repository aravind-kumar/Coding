#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Merge(vector<int>& input,int low,int high)
{
   int mid = low + (high - low)/2;
   int inversions=0;

   vector<int> left(input.begin()+low,input.begin() + mid+1);
   vector<int> right(input.begin() + mid+1,input.begin() + high+1);
   int leftIndex = 0; 
   int rightIndex = 0;
   int sortedIndex = low;
   
   while(leftIndex < left.size() 
         &&
	 rightIndex < right.size())
   {
       if(left[leftIndex] < right[rightIndex]) 
       {
          input[sortedIndex] = left[leftIndex];
          ++sortedIndex;
          ++leftIndex; 
       }
       else
       {
           input[sortedIndex] = right[rightIndex];
           ++sortedIndex;  
           ++rightIndex;
           
           inversions+=mid-leftIndex+1;
       }
   }

   while(leftIndex < left.size())
   {
      input[sortedIndex] = left[leftIndex];
      ++sortedIndex;
      ++leftIndex;
   }
   
   while(rightIndex < right.size())
   {
      input[sortedIndex] = right[rightIndex];
      ++sortedIndex;
      ++rightIndex;
   }
   return inversions;
}

int CountInversions(vector<int>& input,unsigned int low,unsigned int high)
{
   unsigned int inversions=0;
   if(low<high)
   {
        int mid = (low) + (high-low)/2;
	inversions=CountInversions(input,low,mid);
        inversions+=CountInversions(input,mid+1,high);
        inversions+=Merge(input,low,high);
   }
   return inversions;
}

void PrintVector(vector<int>& input)
{
    for(auto&& elem : input)
    {
        cout<<elem<<"\n";
    }
}

int main()
{
   int numOfInput;
   vector<int> inputVector;
   cout<<"\n Enter the number of inputs";
   cin>>numOfInput;
   for(int i=0;i<numOfInput;++i)
   {
        int input;
        cout<<"\n Enter the input "<<i+1<<":";
        cin>>input;
        inputVector.push_back(input);
   }
   cout<<"\n The number of Inversions "<<CountInversions(inputVector,0,inputVector.size() - 1)<<"\n";
   PrintVector(inputVector);
   return 0;
}
