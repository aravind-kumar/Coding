#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

using std::cout;
using std::cin;
using std::vector;


void getInput(vector<int>& input)
{
    int num;
    cout<<"\n Enter the number of elements";
    cin>>num;
    cout<<"\n Enter the elements";
    for(int i=0;i<num;++i)
    {
       int inputNum;
       cin>>inputNum;
       input.push_back(inputNum);
    }
}

int maxDifference(const vector<int>& input)
{
   int diff = std::numeric_limits<int>::max();
   int maxNum = 0;
   for(auto&& elem : input)
   {
     maxNum = std::max(maxNum,elem-diff);
     diff = std::min(diff,elem); 
   }   
   return maxNum;
}

int main()
{
   vector<int> input;
   getInput(input);
   cout<<"\n The maximum capacity is "<<maxDifference(input);
   return 0;
}


