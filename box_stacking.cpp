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

   vector<int> output;
   transform(dimenstions.begin(),dimenstions.end(),back_inserter(output),
             [](array<int,3> input) { return input[0];});

   for(int i=1;i<output.size();++i)
      for(int j=0;j<i;++j)
          if(dimenstions[j][1] > dimenstions[i][1] 
	      &&
             dimenstions[j][2] > dimenstions[i][2]
              && 
             output[i] < dimenstions[j][0] + output[j])
                  output[i] = dimenstions[j][0] + output[j];
   return *(max_elment(output.begin(),output.end()));
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
