#include <iostream>
#include <string>

using namespace std;

char getStrobogrammatic(char c)
{
    switch(c)
    {
      case '1' : return '1'; 
      case '0' : return '0';
      case '8' : return '8'; 
      case '9' : return '6';
      case '6' : return '9';
      default: return ' ';
   }

}

bool isStrobogrammatic(string num)
{
  string output;
  transform(num.rbegin(),num.rend(),back_inserter(output),getStrobogrammatic);
  return num==output;

}
int main()
{
  string num;
  cout<<"\n Enter the number ";
  cin>>num;
  cout<<"\n Is number Strobogrammatic" <<isStrobogrammatic(num);
}
