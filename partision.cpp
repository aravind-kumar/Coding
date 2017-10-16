#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


//Assume that theres a wall on the LHS of the array.
// And all the elements on the right of the array represent elements greater than pivot
// And all the elements on the left of the wall represent the elements less than pivot.
// we start of the wall placed at the left side of the array.
// we assume that all the elements to the right of the wall are greater than the pivot.
// and we iterate through the array. at any given time if we find an element less than pivot we 
/// should be placing it before the wall and incrementing wall.
/// However this would result in a push of all the elements.
/// Hence what we do is we swap it with the element next to wall and increment wall.
void partision(vector<int>& givenInput,int pivotIndex)
{
   int wall=-1;
   int pivotElement = givenInput[pivotIndex];
   for(int currentElement = 0; currentElement <= givenInput.size()-1;++currentElement)
   {
      cout<<"\n Current Element is "<<givenInput[currentElement];
      if(givenInput[currentElement] <= pivotElement)
      {
         ++wall;
         cout<<"Swapping"<<currentElement;
   
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
