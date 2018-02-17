#include <iostream>
using namespace std;
int main()
{
   int n;
   int count=0;
   cout<<"\n Enter the number ";
   cin>>n;
   while(n!=0){
      n=n&(n-1);
      ++count;
   }
   cout<<"\n The number of set bits are "<<count;
   return 0;
}
