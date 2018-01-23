#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;

//Wall1 and Wall3 are partitions to hold the respective values.
//Wall2 is the iterator to iterate the array and swap values
//We do not increment wall2 when we encounter a '2'  and are swapping with wall3
// This is because wall3's swapped value might contain a 2 or 0 or 1. We dont know 
// Hence we maintain the same value 
//    1 0 2 2 1 0
//    ^         ^
//    L         H
//    M
//
//    Mid != 0 || 2
//    Mid++
//
//    1 0 2 2 1 0
//    ^ ^       ^
//    L M       H
//
//    Mid == 0
//    Swap Low and Mid
//    Mid++
//    Low++
//
//    0 1 2 2 1 0
//      ^ ^     ^
//      L M     H
//
//    Mid == 2
//    Swap High and Mid
//    High--
//
//    0 1 0 2 1 2
//      ^ ^   ^
//      L M   H
//
//    Mid == 0
//    Swap Low and Mid
//    Mid++
//    Low++
//
//    0 0 1 2 1 2
//        ^ ^ ^
//        L M H
//
//    Mid == 2
//    Swap High and Mid
//    High--
//
//    0 0 1 1 2 2
//        ^ ^
//        L M
//          H
//
//    Mid <= High is our exit case
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
