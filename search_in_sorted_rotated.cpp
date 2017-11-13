#include <iostream>
#include <vector>
#include <limits>

using std::cout;
using std::cin;
using std::vector;

void getInput(vector<int>& input)
{
   int num;
   cout<<"\n Enter the number of inputs";
   cin>>num;
   cout<<"\n Enter the elements";
   for(int i=0;i<num;i++)
   {
      int givenInput;
      cin>>givenInput;
      input.push_back(givenInput);
   }
}

int binarySearch(const vector<int>& input,
		 const int num)
{
   int low = 0;
   int high = input.size();
   int mid = -1;
   while(low<high)
   {
      mid = low + (high-low)/2;
      int value = (input[mid] < input[0]) == (num < input[0]) ?
		  input[mid] :
		  (num < input[0]) ? std::numeric_limits<int>::lowest() :
                  std::numeric_limits<int>::max() ; 
     if(value < input[high])
        high = mid-1; 
     else if(mid > input[high])
        low = mid+1;
     else
        return mid;
   }
   return -1;
}

int main()
{
   int num;
   vector<int> input;
   getInput(input);
   cout<<"\n Enter the element to be searched";
   cin>>num;
   cout<<"\n The element to be searched for is"<<binarySearch(input,num); 
   return 0;
}


