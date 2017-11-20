#include <iostream>
#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

int minNumOfTrials(int numOfEggs,int numOfFloors)
{
   if(numOfFloors ==0 || numOfFloors ==1 || numOfEggs==1)
      return numOfFloors;
   
   int minNum=numeric_limits<int>::max();
   for(int i=1;i<=numOfFloors;++i)
   {
       minNum = min(minNum,
		    max(minNumOfTrials(numOfEggs-1,i-1),
			minNumOfTrials(numOfEggs,numOfFloors-i)));
   } 
   cout<<"\n Returning" <<minNum+1<<"\n";

   return minNum+1;
}

int main()
{
   int numOfEggs,numOfFloors;
   cout<<"\n Enter the number of eggs";
   cin>>numOfEggs;
   cout<<"\n Enter the number of floors";
   cin>>numOfFloors;
   cout<<"\n The minum number of trials needed are"<<minNumOfTrials(numOfEggs,numOfFloors);

   return 0;
}
