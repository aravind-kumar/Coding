#include <iostream>
#include <math.h>

using namespace std;

bool isPerfect(int num)
{
  if(num==1)
    return false;
  int sum=0;
  int rootNum = sqrt(num);
  for(int i=2;i<=rootNum;++i)
  {
     if(num%i == 0)
     {
        sum+=i;
        int otherDivisor = num/i;
        if(otherDivisor != i) sum+= otherDivisor;
     }
  }
  ++sum; //account for 1.
  return sum == num;
}

int main()
{
   int num;
   cout<<"\n Enter the number to check if its perfect";
   cin>>num;
   cout<<"\n Is the number perfect "<<isPerfect(num); 
   return 0;
}
