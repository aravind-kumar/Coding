#include <iostream>
#include <vector>

using namespace std;

void PrintVector(vector<int> inputElements)
{ 
   for(auto&& element : inputElements)
   {
     cout<<element;
   }
}

int GetMaxSubArray(vector<int> inputElements)
{ 
   int sum_end_here=0;
   int max_sum_till_now=inputElements[0];
   for(int i=0;i<inputElements.size();++i)
   {
      sum_end_here+=inputElements[i];
      if(sum_end_here<0)
      {
         sum_end_here=0;
      }
      if(sum_end_here > max_sum_till_now)
      {
         max_sum_till_now = sum_end_here;
      }
   }
   return max_sum_till_now;
}

int main()
{
   int num;
   vector<int> inputElementVector;

   cout<<"\n Enter the number of elements";
   cin>>num;
   
   for(int i=0;i<num;++i)
   {
     int inputElement;
     cin>>inputElement;
     inputElementVector.push_back(inputElement); 
   }
   cout<<GetMaxSubArray(inputElementVector); 
   return 0;
}
