#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <cstring>

using std::array;
using std::string;
using std::cout;
using std::cin;



//How does it work?
//The recursion starts with the first character of the first number
// Then first character of second character is added
// This follows on until we reach the last number
// Upon reaching the last number we append all of its characters to the number
// And recurse back , but this time the size would match the given number size
// Hence it would print it.
// Now when the last number printing is done.
// We go the second character of the last but one number.
// Now with second character we again iterate though all the character of the last number
// Now repeat the same for the third character of the last but one number
// The same process continues.

// One could imagine this as DFS with all the character of a node having an edge to all other 
// character to the next number. 
typedef array<string,10> phoneMap;

static phoneMap keyboard = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printPermuHelper(const string& num,int index,string result)
{
   if(index == num.size())
   { 
     cout<<result<<"\n";
   }
   else
   {
      char currentNum = num[index];
      int  key = currentNum - '0';
      for(auto&& character : keyboard[key]) 
      {
          result[index] = character;
          printPermuHelper(num,index+1,result);
      }
   }

} 

void removeNumbersWithEmptyValue(string& num)
{
   auto newEnd = remove_if(num.begin(),num.end(),
	         [](char elem) 
                 {
                    return (::keyboard[elem-'0']).compare("") == 0;
                 });
   string newString(num.begin(),newEnd);
   num = newString; 
}
 
void printPermu(string& num)
{
    string result(num.size(),0);
    removeNumbersWithEmptyValue(num);
    printPermuHelper(num,0,result);
}
  
int main(int argc,char* argv[])
{
   string input;
   cout<<"\n Enter the string";
   cin>>input;
   printPermu(input);
   return 0;
}

