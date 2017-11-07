#include <iostream>

using std::cout;
using std::cin;

unsigned int add(const unsigned int& a,const unsigned int& b)
{
   unsigned int sum=0,k=1,carrying=0;
   while(k)
   {
      unsigned int ak = (a & k) , bk = (b & k);
      unsigned int carryout = (ak & bk) | (bk & carrying) | (ak & carrying);
      sum |= a^b^carrying;
      carrying =  carryout << 1;
      k<<=1;
   }
   return sum;
}

unsigned int mul(const unsigned int& a,unsigned int b)
{
   unsigned int sum=0,k=1;
   while(k)
   {
      if(a & k)
      	sum=add(sum,b);      
      k<<=1;
      b<<=1;
   }
   return sum;
}

int main()
{ 
   int a,b;
   cout<<"\n Enter the input number";
   cin>>a>>b;
   cout<<"\n The multiplication is "<<mul(a,b);   
   return 0;
}
