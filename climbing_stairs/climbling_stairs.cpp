#include <iostream>

using namespace std;

int climbStairs(int n) {
    int prev=1,prevprev=1;
    if(n==1)
       return 1;
    int count=0;
    for(int i=2;i<=n;++i)
    {
        count=prev+prevprev;
        prevprev=prev;
        prev=count;
     }
     return count;
}


int main()
{
   int num;
   cout<<"\n Enter the number of stairs ";
   cin>>num;
   cout<<"\n The number of ways to reach the top are "<<climbStairs(num);
   return 0;
}
