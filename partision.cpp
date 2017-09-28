#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void partision(vector<int>& givenInput,int pivotIndex)
{
   int wall=-1;
   int pivotElement = givenInput[pivotIndex];
   for(int currentElement = 0; currentElement < givenInput.size();++currentElement)
   {
      if(givenInput[currentElement] <= pivotElement)
      {
         ++wall;
         swap(givenInput[currentElement],givenInput[wall]);
      }    
   }
   swap(givenInput[wall+1],givenInput[pivotIndex]);
}

void printVector(vector<int> givenInput)
{
   for(auto&& elem : givenInput)
   {
      cout<<elem<<" ";
   }
}
int main()
{
    int numOfInputs,partisionElement;
    vector<int> input;
    cout<<"\n Enter the number of inputs";
    cin>>numOfInputs;
    for(int i=0;i<numOfInputs;++i)
    {
         int givenInput;
         cin>>givenInput;
         input.push_back(givenInput);
    }
    cout<<"\n Enter the index of partision element";
    cin>>partisionElement;
   
    partision(input,partisionElement);
    printVector(input);
    
    return 0;
}
