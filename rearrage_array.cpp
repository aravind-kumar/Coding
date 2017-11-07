#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <assert.h>

using std::cout;
using std::cin;
using std::transform;
using std::vector;

void getInput(vector<int>& input)
{
   int n;
   cout<<"\n Enter the number of elements";
   cin>>n;
   cout<<"\n Enter the elements";
   for(int i=0;i<n;++i)
   {
      int inputNum;
      cin>>inputNum;
      assert(inputNum>=0 && inputNum<=n-1);
      input.push_back(inputNum);
   }
}

void rearrange(vector<int>& input)
{
   int n = input.size();

   auto encode = [input,n](int i) 
		 { return (input[input[i]] % n)*n;};  

   auto decode = [n] (int i)
 		 { return i/n;};
   
   transform(input.begin(),input.end(),input.begin(),encode);

   transform(input.begin(),input.end(),input.begin(),decode);
}

void print(const vector<int>& input)
{
   for(auto&& elem : input)
      cout<<elem<<"--->";
}

int main()
{
   vector<int> input;
   getInput(input);
   rearrange(input);
   print(input);
   
   return 0;
}
