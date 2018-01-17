#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotations(vector<int>& input,int num)
{
  int n = input.size();
  reverse(input.begin(),input.begin()+n-num-1);
  reverse(input.begin()-n-num-1,input.end());
  reverse(input.begin(),input.end());
}

int main()
{
  vector<int> input;
  int num;
  cout<<"\n Enter the number of inputs";
  cin>>num;
  cout<<"\n Enter the inputs";
  for(int i=0;i<num;++i)
  {
     int inputNum;
     cin>>inputNum;
     input.push_back(inputNum);
  }
  cout<<"\n Enter the number of rotations to be made ";
  cin>>num;
  rotations(input,num);
  for(auto&& num : input)
     cout<<num<<"--->"<<endl;

   return 0;
}
