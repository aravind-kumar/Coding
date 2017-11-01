#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include<cstdlib>

template <typename T>
int custom_parition(std::vector<T>& input,int k)
{
   int wall=-1;
   int pivotElement = input[k];
   for(int i=0;i<input.size();++i)
   {
      if(input[i]<=pivotElement)
      {
        wall++;
        std::swap(input[wall],input[i]);
      }   
   }
   std::swap(input[wall+1],input[k]);
   return wall+1;
}

template <typename T>
int find_kth_element(std::vector<T> input,int k)
{

    if(input.size()==0 || ((k < 0) || (k>(input.size()-1))))
	return 0;
    else
    {
       int randomElement = rand() % (input.size()-1);
       typename std::vector<T>::iterator iter = std::partition(input.begin(),input.end(),
          					   [randomElement](T elem) 
	            		                   { return (elem < randomElement);});
       std::cout<<"\n The retured iterator is" <<(input.end() == iter);
       for_each(input.begin(),input.end(),[](int num) { std::cout<<num<<","; });
       int rank = (find (input.begin(),input.end(),randomElement)) - input.begin();
       std::cout<<"\n Rank is " <<rank;
       if(rank == k)
	  return *iter;
       else if(rank > k)
       {  
          std::vector<int> leftHalf(input.begin(),input.begin()+rank);
	  return find_kth_element(leftHalf,k);
       }
       else
       {
          std::vector<int> rightHalf(input.begin()+rank,input.end());
	  return find_kth_element(rightHalf,k-rank-1);
       }
    }
    return -1;
}

int main()
{
   int num;
   std::vector<int> inputArray;
   std::cout<<"\n Enter the number of elements";
   std::cin>>num;
   std::cout<<"\n Enter the elements";
   for(int i=0;i<num;++i)
   {
      int input;
      std::cin>>input;
      inputArray.push_back(input);
   }
   std::cout<<"\n Enter the rank of element to be found";
   std::cin>>num;
   std::cout<<find_kth_element(inputArray,num);
   return 0;
}
