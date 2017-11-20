#include <iostream>
#include <vector>


template <typename T>
int find_kth_largest(const std::vector<T>& inputVector1,
	             int start1,
                     const std::vector<T>& inputVector2,
	             int start2,
                     int k)
{
   if (k==2)
   {
     return second_largest(inputVector1,start1,
			   inputVector2,start2);
   }

   int mid1 = inputVector1[k/2];
   int mid2 = inputVector2[k/2];
   
   if(mid1>mid2)
   {
      return find_kth_largest(inputVector1,
   }

}

int main()
{
   return 0;
}
