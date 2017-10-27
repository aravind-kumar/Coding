#include <iostream>
#include <vector>


//This program finds the local miniama.
// Its possible that there are more than one local minima
// In that case there we can print any one minima
// A minima is defined as a value in the array such that 
// its less than both of its neighbors.
// The given array is not in sorted order
// However its given that the A[0]>A[1] and A[n-2] < A[n-1]
// If such a condition occrs in an array we can prove that 
// there would be atleast one minma.
// How ?? we are given that A[0] > A[1] 
// Now what could be the value of A[2] it could be > or < 
// than A[1].
// Lets assume that its > than A[2] i.e A[0] > A[1] > A[2] ...
// Now if we extrapolate this we would be decreasing series
// and in that case we wouldnt get a minima.
// However if we were do so then the second condition A[n-2] < A[n-1]
// would be false.
// Hence if A[n-2] < A[n-1] there would be a minima.

//Method1 : Use linear search to find the minima.
// Method2 : Binary Search iff there are no duplicates.
//           We check if mid matches the condition 
//           if so we return mid.
//           Next we check if Mid-1 < Mid .
//           If so then the left half is from 0 to Mid has 
//           the same initial conditions as given in the given 
//           in the question wherein the last elements are less.
//           Hence the minima must exsist here.
//           The opposite applies to moving right.
//           In that case we already know that the end has an increasing 
///          series and if Mid+1 > Mid then its similar to Condition 1 of the
//           question.
//           Note: This method can only be applied if the elements are distinct 
//           If all the elements are same say 1 then there is no minima.
template <typename T>
int find_local_minima(const std::vector<T> &input)
{
   int low = 0 ;
   int high = input.size();
   while(low<high)
   {
      int mid = low+(high-low)/2;
      if(input[mid] <= input[mid-1] 
                && 
        input[mid] <= input[mid+1])
         return mid;
      else if(input[mid-1] <= input[mid])
         high = mid;
      else 
	low = mid;
   }
   return -1;
}

int main()
{
   int num;
   std::vector<int> inputArray;
   std::cout<<"\n Enter the number of elements";
   std::cin>>num;
   std::cout<<"\n Enter the elments";
   for(int i=0;i<num;++i)
   {
      int inputNum;
      std::cin>>inputNum;
      inputArray.push_back(inputNum);
   }
   std::cout<<"\n The local minima is "<<find_local_minima(inputArray);  
   return 0;
}
