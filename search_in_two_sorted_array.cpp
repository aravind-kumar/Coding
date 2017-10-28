#include <iostream>
#include <vector>
#include <math.h>


// There are many ways to solve the kth smallest element problem.
// Simple approach would be to something simlar to a merge sort 
// We merge all the elements and return the kth element.
// Method 2: Instead of merging we could just iterate thorugh both 
// the input array with i and j pointer till we reach k iterations.
// Method 2 : We could also maintain a min heap to find the min.
// Method 3 : logK steps using binary search.
// We find the k/2 the element on both the arrays and compare.
// We ignore the first half of the array whichever has a lower value.
// This is because, k/2 the element has atleast k/2 elements preceding it.
// Hence the kth wouldnt be in that and thats why we ignore it.

template <typename T>
int find_second_min(const std::vector<T>& inputVector1,
    		    int start1,
		    const std::vector<T>& inputVector2,
    		    int start2)
{
   std::vector<T> temp = {inputVector1[start1],inputVector1[start1+1],
             		  inputVector2[start2],inputVector2[start2+1]}; 
   int prevMin,min = temp[0];
   for(auto&& num : temp)
   {
     if(num > min)
     {
        prevMin = min;
        min = num;
     }
   }
   return prevMin;
}

template <typename T>
int index_in_merged_array(const std::vector<T>& inputVector1,
                          int start1, 
			  const std::vector<T>& inputVector2,
                          int start2, 
  			  const int& k)
{
   if(k<=2)
   {
      return find_second_min(inputVector1,start1,inputVector2,start2);
   }
   int LArray = inputVector1[start1 + k/2];
   int RArray = inputVector2[start2 + k/2];
   
   if(LArray < RArray)
   {
      return index_in_merged_array(inputVector1,start1 + floor(k/2),
				   inputVector2,start2,(ceil(k/2))); 
   }
   else
      return index_in_merged_array(inputVector1,start1,
				   inputVector2,start2+ floor(k/2),(ceil(k/2))); 
}

int main()
{
   int num;
   std::vector<int> input1;
   std::vector<int> input2;
   std::cout<<"\n Enter the number of elements k ";
   std::cin>>num;
   std::cout<<"\n Enter the elements of input1";
   for(int i=0;i<num;++i)
   {
     int input;
     std::cin>>input;
     input1.push_back(input);
   }
   std::cout<<"\n Enter the elements of input2";
   for(int i=0;i<num;++i)
   {
     int input;
     std::cin>>input;
     input2.push_back(input);
   }  
   std::cout<<"\n Enter the kth element to be searched for";
   std::cin>>num;
   std::cout<<"\n The answer is "<<index_in_merged_array(input1,0,input2,0,num);  
   return 0;
}
