#include <iostream>


uint64_t reverse(uint64_t n)
{
   uint64_t result=0;
   for(int i=0;i<64 && n;++i,n=n/2)
   {
      result = result<<1;
      result = result | (n & 1); 
   }
    return result;

}
int main()
{
   uint64_t n;
   std::cout<<"\n Enter the number";
   std::cin>>n;
   std::cout<<"\n The reversed num is "<<reverse(n);
   return 0;
}
