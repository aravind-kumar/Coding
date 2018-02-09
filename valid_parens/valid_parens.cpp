#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isValid(vector<char> s)
{
   stack<char> input;
        for(auto&& c:s) {
            switch(c) {
                case '{':
                case '(':
                case '[': input.push(c); break;             
                case ')': if(input.size() == 0 || input.top() != '(') return false; else input.pop(); break;
                case '}': if(input.size() == 0 || input.top() != '{') return false; else input.pop(); break;
                case ']': if(input.size() == 0 || input.top() != '[') return false; else input.pop(); break;
                default : return false;
            }
        }
        return input.size()==0;
}

int main()
{
  vector<char> input;
  int num;
  cout<<"\n Enter the number of elements";
  cin>>num;
  cout<<"\n Enter the parens";
  for(int i=0;i<num;++i) {
     char inputChar;
     cin>>inputChar;
     input.push_back(inputChar); 
  }
  cout<<"\n Is it a valid paren"<<isValid(input); 
   return 0;
}
