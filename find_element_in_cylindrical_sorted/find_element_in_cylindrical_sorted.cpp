#include <iostream>
#include <vector>


//We are given a roatated array and are asked to find the minimum 
//element.
//Notice that in a rotated array the elements after end are > than the end.
//All the elements would be greater than end till we reach the start of array.
// We can make use of this fact to do a binary search.
//Upon computing the mid of the element we check if its > or < than the end element.
//If its greater then we know that we are left half of the array and that we need to procced forward.
//If its less then we know that we are in the right half of the array and that we need to proceed backward.
template <typename T>
int find_smallest_element(const std::vector<T>& input)
{  
    int low=0,high=input.size()-1;
    while(low<=high)
    {
        int mid = low + ((high-low) >>2);
        if (input[mid] > input[mid+1]) return mid+1;
        else if(input[mid] > input[high])
	     low = mid+1;
        else 
             high = mid-1;
    }
    return -1;
}

int main()
{
   int num;
   std::vector<int> inputArray;
   std::cout<<"\n Enter the number of elements ";
   std::cin>>num;
   for(int i=0;i<num;++i)
   {  
       int input; 
       std::cin>>input;
       inputArray.push_back(input);
   }
   std::cout<<"\n The smallest element is "<<find_smallest_element(inputArray);
   return 0;
}
