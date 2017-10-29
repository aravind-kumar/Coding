#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <set>


// This is a variation to print all possible character of the number and its prefixes.

typedef std::array<std::string,10> phoneMap;
typedef std::set<std::string> permutations;

permutations getPhoneNumCombinations(int num,const phoneMap map)
{ 
 permutations final={""};
 while(num)
 {
   int digit = num%10;

   for(auto&& character: map[digit])
   {
      std::set<std::string> newOutput;
      for(auto element : final)
      {
          element.insert(element.begin(),character); 
          newOutput.insert(element);
      }
      for(auto&& elements : newOutput)
         final.insert(elements); 
   }
   num=num/10; 
 }
  return final;
}

int main(int argc,char *argv[])
{
  const std::array<std::string,10> map = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
  int num;
  std::cout<<"\n Enter the number to compute";
  std::cin>>num;
  for(auto&& elements : getPhoneNumCombinations(num,map))
  {
     std::cout<<elements<<"\n";
  }
  return 0;
}
