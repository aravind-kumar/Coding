#include <iostream>
#include <string>
using namespace std;

bool isMatch(char *input,char* regex)
{
  if(input == '\0' && regex == '\0') 
      return true;

  if(input != '\0' && regex != '\0') {
     
    if(input+1 != '*') 
    {
       if((*input == *regex) || (*input != '\0' && *regex == '.'))
          return isMatch(input+1,regex+1);
    }
    
    while( (*input == *regex) || ( *regex == '.' && *input != '\0')) 
    {
       if(isMatch(input,regex+2)) 
         return true;
       ++input;
    }
    return isMatch(input,regex+2);    
  } 
  return false;
}


int main()
{
  string input,regex;
  cout<<"\n Enter the input String";
  cin>>input;
  cout<<"\n Enter the regex";
  cin>>regex;
  cout<<"\n The result of the matching is "<<isMatch(input.c_str(),regex.c_str()); 

   return 0;
}
