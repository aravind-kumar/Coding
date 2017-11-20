#include <iostream>
#include <list>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;

list<int>::iterator findPos(list<int> inputList,int num)
{
    return find_if(inputList.begin(),inputList.end(),
			 [num](int input1)
		         {
   		            return input1>num;	
               		 });
                       
}

void insert(list<int>& inputList,int num)
{
   if(inputList.size()==0
     ||
     inputList.back()<num)
   {
     inputList.push_back(num); 
   }
   else if(inputList.front() > num)
   {
      inputList.push_front(num);
   }
   else 
   {
      list<int>::iterator it = findPos(inputList,num);
      inputList.insert(it,num);
   }

   for_each(inputList.begin(),inputList.end(),[](int n) { cout<<"\n "<<n;});
}

int main()
{
   int num;
   list<int> inputList;
   cout<<"\n Enter the number of inputs";
   cin>>num;
   cout<<"\n Enter the inputs";

   for(int i=0;i<num;++i)
   {
     int givenInput;
     cin>>givenInput;
     inputList.push_back(givenInput);
   }
   cout<<"\n Enter the element to be inserted";
   cin>>num;
   insert(inputList,num);
   assert(is_sorted(inputList.begin(),inputList.end()));
   return 0;
}
