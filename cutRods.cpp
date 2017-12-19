#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

bool isNonZero(int num)
{ 
   return num>0;
}

vector<int> cutRods(vector<int> input)
{
    vector<int> output;
    input.erase(remove_if(input.begin(),input.end(),[](int num) { return num==0;}));
    while(!input.empty())
    {
       cout<<"\Entering loop";
       int min = *(min_element(input.begin(),input.end()));
       cout<<"\n The minim element"<<min;
       transform(input.begin(),input.end(),input.begin(),
       	       	[min](int num){ return num-min;});

       int count = count_if(input.begin(),input.end(),
			    [](int num) { return num==0;});
       cout<<"\n The count is "<<count;
       output.push_back(count);	
       input.erase(remove_if(input.begin(),input.end(),[](int num) { return num==0;}));
    }
    return output;
}

int main()
{
    vector<int> input = {1,2,3,4};
    cutRods(input);
    return 0;
}
