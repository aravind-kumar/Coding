#include <iostream>
#include <vector>

using namespace std;

bool doesSumExsist(vector<int> input,int sum)
{
   if(sum==0)
     return true;
   if(sum != 0 && input.empty())
     return false;

   int lastElem = input.back();
   input.pop_back();
   return doesSumExsist(input,sum) 
	  || 
          doesSumExsist(input,sum-lastElem);
}

int main()
{
   int num;
   vector<int> input;
   cout<<"\n Enter the number of elements to in the array";
   cin>>num;
   for(int i=0;i<num;++i)
   {
     int givenNum;
     cin>>givenNum;
     input.push_back(givenNum);
   }
   cout<<"\n Enter the sum to check ";
   cin>>num;
   cout<<"\n Does the sum exsits in the array "<<((doesSumExsist(input,num))? "yes" : "no") ; 
   return 0;
}
