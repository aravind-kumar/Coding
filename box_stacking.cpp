#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <array>
#include <utility>

using namespace std;

void getInput(vector<array<int,3>>& boxDimenstions)
{
   int n;
   cout<<"\n Enter the number of elements";
   cin>>n;
   for(int i=0;i<n;i++)
   {
      array<int,3> dimenstions;
      for(int j=0;j<3;++j) 
      {
         int num;
         cout<<"\n Enter the "<<j+1<<" value";
         cin>>num;
         dimenstions[j] = num;
      }
      boxDimenstions.push_back(dimenstions);
   }
}

void printBoxes(const vector<array<int,3>>& input)
{
   for(auto&& box : input)
   {
      for(auto&& dimenstion : box)
      {
         cout<<dimenstion<<"--->";
      }
      cout<<"\n";
   }
}

void getAllRotations(vector<array<int,3>>& dimenstions)
{

    vector<array<int,3>> output;
    auto generateRotations = [&output] (array<int,3> input)
			     {
                                output.push_back(input);
				swap(input[0],input[2]);
                                output.push_back(input);
 				swap(input[0],input[1]);
                                output.push_back(input);   
                             };
    for_each(dimenstions.begin(),dimenstions.end(),generateRotations);
    dimenstions = output;
}

int getLongestHeight(vector<array<int,3>> dimenstions)
{
   sort(dimenstions.begin(),dimenstions.end(),
       [] (auto input1,auto input2) 
       { return input1[0] > input2[0];});
   return -1;
}

int main()
{
   typedef array<int,3> dimensions;
   vector<dimensions> boxDimenstions;
   getInput(boxDimenstions);  
   getAllRotations(boxDimenstions);
   cout<<"\n The longest height is " <<getLongestHeight(boxDimenstions);
   
   return 0;
}
