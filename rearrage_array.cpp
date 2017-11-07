#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <assert.h>

using std::cout;
using std::cin;
using std::transform;
using std::vector;

// Question : Rerrange all the elements in the array such that A[i] =A[A[i]]
// Every element is would be in the range of 0 to n-1;
// Catch : We shouldnt replace all the elements with A[i] = A[A[i]]
//         because it would owerrite the values in the array.
//         which would mean that we loose the old value and thus wrong output
//Method1: Would be to create a new array and use the old array to copy all the new values
//         Without modifying the array.
//Method2: There is trick we can use to make that the size is O(1)
//         Note that this method would only work if N*N wouldnt overflow.
//         We can use a variable to store two value at the same time 
//         We use the formula A = B + (C % n) *n;
//			      A % n = C
// 			      A / n = B

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
