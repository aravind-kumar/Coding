#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Bug When its reverse order
//When it return 0 the loop returns -1
//Sometimes both return 0
void PrintVector(vector<int>const& input) 
{
   for(auto && elem : input)
   {
      cout<<elem;
   }
}
int BinarySearch(vector<int>& input,
                  int low,
		  int max,
                  int key)
{
    if(key<input[max])
    {
        int mid = (low) + (max - low)/2; 
        int prevElem = input[mid-1];
        int nextElem = input[mid];
       
        if(prevElem < key 
           &&
           nextElem > key)
        {
            return mid;
        } 
        else if(prevElem > key
                &&
                nextElem > key)
        {
           return BinarySearch(input,low,mid-1,key); 
        }
        else if(prevElem < key
		&&
 		nextElem < key)
	{
           return BinarySearch(input,mid+1,max,key); 
 	}
    }
    return max+1; 
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
      cout<<BinarySearch(input,0,i-1,key);
      cout<<"************"; 
      cout<<j<<"\n";
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
