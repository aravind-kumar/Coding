#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isDuplicates(vector<int> nums)
{
   return nums.size()>unordered_set<int>(nums.begin(),nums.end()).size();
} 

int main()
{
  int num;
  vector<int> input;
  cout<<"\n Enter the size of the input";
  cin>>num;
  cout<<"\n Enter nums";
  for(int i=0;i<num;++i)
  {
    int givenNum;
    cin>>givenNum;
    input.push_back(givenNum);
  }
  cout<<"\n Does it have duplicates"<<isDuplicates(input);
   return 0;
} 

