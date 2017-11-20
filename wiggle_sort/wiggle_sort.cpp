#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
void printArray(vector<int> inputArray)
{
    for(auto&& element : inputArray)
    {
       cout<<element<<"\n";
    }
}

void wiggleSort(vector<int> inputArray)
{
   for(int i=0;i<inputArray.size();i+=2)
   {
       if(i>0 && inputArray[i] < inputArray[i-1])
          swap(inputArray[i],inputArray[i-1]);
       if(i<inputArray.size()-1 && inputArray[i] < inputArray[i+1])
          swap(inputArray[i],inputArray[i+1]);
   }   
   printArray(inputArray);
}

int main()
{
   int numOfInputs;
   vector<int> inputArray;
   cout<<"\n Enter the number of inputs";
   cin>>numOfInputs;
   for(int i=0;i<numOfInputs;++i)
   {
      int givenInput;
      cin>>givenInput;
      inputArray.push_back(givenInput);
   }
   wiggleSort(inputArray);
   return 0;
}
