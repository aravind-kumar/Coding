#include <iostream>

using namespace std;

int countSetBits(int num)
{
   int count=0;
   while(num)
   {
      num=num&(num-1);
      ++count;
   }
   return count;

}

int hammingDistance(int num1,int num2)
{ 
    return countSetBits(num1^num2);
}

int main()
{
   int num1,num2;
   cout<<"\n Enter the number";
   cin>>num1;
   cout<<"\n Enter the second number";
   cin>>num2;
   cout<<"\n The hamming distance is "<<hammingDistance(num1,num2);
   return 0;
}
