#include <iostream>
#include <vector>
#include <limits>

using std::cout;
using std::cin;
using std::vector;


//Question : Given a sorted rotated array, Find the index of an element
//Analysis:
//There are two inputs we have an targer value and pivot element
//The pivot element is the element in the array where there is a sudden dip
//Hence the array can be divided into 2 subarrays
//1.Elements before pivot 
//2.Elements after pivot
//Note that elements before pivot and after pivot are sorted
//We perform a modified binary search
//How do we differentiate between the two subarrays ?
// The elements before the pivot are greater than input[0]
// The elements after the pivot are less than input[0].
// Now the mid of binary search and the target can be 3 possible situations
// 1.Both are left half of the input (Left : Before Pivot)
// 2.Both are in right half of the input
// 3.One is in left and the other is in right half or vice-versa.
// For cases 1 and 2 we can search in the respective subarrays i.e left of right
// since they are already in sorted order
// For case 3 we have to check if the search element is in the right or left half
// And we have to transition to that sub-half.
// Hence we set the value appropiately for the input[mid] to take the following decision.

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


