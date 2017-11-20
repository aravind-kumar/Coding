#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int FindMajority(vector<int> inputVector)
{
    vector<int>::iterator i,j;
    for(i=inputVector.begin(),j=i+1;j<inputVector.end();)
    {
      if(*i != *j)
      {
           i = inputVector.erase(i);
           j = inputVector.erase(i);
      }
      else
      {
         i+=2;
         j+=2;
      }
    } 
    if (inputVector.size()>=1)
    {
       return inputVector[0];
    }
    return -1;
}
int main()
{
   int num;
   vector<int> inputVector;
   cout<<"\n Enter the number of elements";
   cin>>num;
   for(int i=0;i<num;++i)
   {
      int givenInput;
      cin>>givenInput;
      inputVector.push_back(givenInput);
   }
   cout<<"\n The majority element is "<<FindMajority(inputVector);
   return 0;
}
