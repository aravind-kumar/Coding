#include <iostream>
#include <string>
#include <unordered_map>

int romanToInt(std::string s)
{
   std::unordered_map<char, int> romanMap = { { 'I' , 1 },
                                       { 'V' , 5 },
                                       { 'X' , 10 },
                                       { 'L' , 50 },
                                       { 'C' , 100 },
                                       { 'D' , 500 },
                                       { 'M' , 1000 } };
    int sum = romanMap[s.back()];
    for(int i=s.length()-2;i>=0;--i) {
       if(romanMap[s[i]]  < romanMap[s[i+1]]) {
          sum-=romanMap[s[i]]; 
       } else {
          sum+=romanMap[s[i]];
       } 
    }
    return sum;
}

int main()
{
   std::string s;
   std::cout<<"\n Enter the input string";
   std::cin>>s;
   std::cout<<"\n The integer is "<<romanToInt(s);   
   return 0;
}
