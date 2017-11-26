#include <iostream>
#include <stack>
#include <string>

std::string convert(const std::string& input1,
		    const std::string& input2)
{
   if(input1.length() == input2.length())
   {
      std::stack<char> converstionStack;
      std::string result; 
      for(int i=0,j=0;i<input1.length() && j<input2.length();)
      {
         if(!converstionStack.empty() && 
	    converstionStack.top() == input2[j])
         {
           result += "o";
           converstionStack.pop();
           ++j;
         }
         else
         {
           result+="i";
           converstionStack.push(input1[i]);  
           ++i;
         }
      }
      return result;
   }
   return "";
}

int main()
{
   std::string input1,input2;
   std::cout<<"\n Enter the first string" ;
   std::cin>>input1;
   std::cout<<"\n Enter the second string";
   std::cin>>input2; 
   std::cout<<"\n The sequence of opearation to convert str1 to str2 are "<<convert(input1,input2);
   return 0;
}
