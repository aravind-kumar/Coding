#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

void printVector(vector<int> input)
{
    for(auto&& element : input)
    {
        cout<<element;
    } 
}

void partision(vector<int>& input)
{ 
   int i = 0;
   int j = input.size()-1;
   while(i<j)
   {
       while(input[j]==1) --j;

       while(input[i]==0) ++i;
       
       if(i<j)
       { 
          swap(input[i],input[j]);
          --j;
          ++i;
       }
   }
   cout<<i<<" "<<j<<" ";
}

int main()
{
   int numOfElements;
   vector<int>  inputVector;
   cout<<"\n Enter the number of inputs";
   cin>>numOfElements;
   
   cout<<"\n Enter the elements";
   for(int i=0;i<numOfElements;++i)
   {
      int inputElement;
      cin>>inputElement;
      inputVector.push_back(inputElement);
   }
   
   partision(inputVector);
   printVector(inputVector);
    
   return 0;
}
