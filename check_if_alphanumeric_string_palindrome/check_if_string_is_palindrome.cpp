#include <iostream>
#include <string>
#include <ctype>

using namespace std;

bool isPalindrome(const string& input) {
   for(int i=0,j=input.lenght()-1;i<j;++i,--j) {
       while(!isalnum(input[i]) && i<j) ++i;
       while(!isalnum(input[j]) && i<j) --j;
       if(toupper(s[i]) != toupper(s[j]))
           return false;
   }
   return true;    
}

int main()
{
   string input;
   cout<<"\n Enter the string";
   cin>>input;
   cout<<"\n Is palindrome" <<isPalindrome(input);
   return 0;
}
