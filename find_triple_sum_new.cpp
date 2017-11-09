#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


template <typename T>
std::vector<std::vector<T>> findUniqueTripleSum(std::vector<T> input,int sum)
{
   typedef std::vector<std::vector<T>> vectorTriplets;
   vectorTriplets res;
   std::sort(input.begin(),input.end(),std::less<T>());
   for(int i=0;i<input.size();++i)
   {
      int target = -input[i];
      int front = i+1;
      int back = input.size()-1;
      
      while(front<back)
      {
         int sum = input[front] + input[back];
         if(sum<target)
         {
            ++front;
         } 
         else if(sum>target)
         {
             --back; 
         }
         else
         {
            res.push_back({input[i],input[front],input[back]});
            while(front < back && input[front] == (res.back())[1]) ++front;
            while(front < back && input[back] == (res.back())[2]) --back;
         }
      }
       
      int temp = i+1; 
      while( temp < input.size() && input[temp] == input[i]) ++temp;
      i = temp-1; 
   }
   return res;
}
 
template <typename T>
void getInput(std::vector<T>& input)
{
   int num;
   std::cout<<"\n Enter the number of elements";
   std::cin>>num;
   std::cout<<"\n Enter the inputs";
   for(int i=0;i<num;++i)
   {
      int inputNum;
      std::cin>>inputNum;
      input.push_back(inputNum);
   }
}

void printTriplets(std::vector<std::vector<int>> triplets)
{
   for(auto&& triplet : triplets)
   {
       for(auto&& value : triplet)
          std::cout<<value <<" ";
       std::cout<<"\n";
   }

}
int main()
{
   std::vector<std::vector<int>> res;
   std::vector<int> input;
   int sum;
   std::cout<<"\n Enter the sum";
   std::cin>>sum;
   getInput(input);
   res = findUniqueTripleSum(input,sum);
   printTriplets(res);
   return 0;
}
