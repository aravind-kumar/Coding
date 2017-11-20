#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;

void dutchPartision(vector<int>& input)
{ 
    int wall1=0;
    int wall2=0;
    int wall3=input.size()-1;
    while(wall2<=wall3)
    {
        switch(input[wall2])
        { 
            case 0: swap(input[wall1],input[wall2]);
                   ++wall1;
                   ++wall2;
                   break;
           case 1: ++wall2;
                   break;
            case 2:swap(input[wall3],input[wall2]);
                   --wall3;
                   break;
           default:
 	 	   assert(0);
                   break;
        }
    }
}

void printArray(vector<int>& input)
{ 
   for(auto&& elem : input)
   {
      cout<<elem<<" ";
   }

}

int main()
{
   int num;
   vector<int> input;
   cout<<"\n Enter the input size";
   cin>>num;
   for(int i=0;i<num;++i)
   {
     int givenInput;
     cin>>givenInput;
     input.push_back(givenInput);
   }
   printArray(input);
   cout<<"\n---------------------------";
   dutchPartision(input);
   cout<<"\n---------------------------";
   printArray(input);
   return 0;
}
