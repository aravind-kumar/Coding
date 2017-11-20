#include <iostream>

using std::cout;
using std::cin;

unsigned int add(unsigned int a,unsigned int b)
{
  unsigned int sum=0,k=1,carrying=0;
  while(k)
  {
     unsigned int ak=(a & k), bk=(b&k);
     unsigned int carryout = (ak & bk) | (ak & carrying) | (bk & carrying);
     sum|= ak ^ bk ^ carrying;
     carrying = carryout << 1;
     k<<=1;
  }
  return sum;
}

void getInput(unsigned int &a,unsigned int& b)
{
  cout<<"\n Enter the two numbers";
  cin>>a>>b; 
}

int main()
{
   unsigned int a,b;
   getInput(a,b);
   cout<<"\n The addition is "<<add(a,b); 
}
