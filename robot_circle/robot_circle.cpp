#include <iostream>
#include <string>

using namespace std;

bool isCircling(string input)
{
   pair<int,int> coord = {0,0};
   for(auto&& character : input)
   {
      switch(character)
      {
        case 'U' : coord.second++; break;
        case 'D' : coord.second--; break;
        case 'L' : coord.first++; break;
        case 'R' : coord.first--; break;
      }
   }
   return coord.first==0 && coord.second==0;
}

int main()
{
   string str;
   cout<<"\n Enter the sequence of moves";
   cin>>str;
   cout<<"\n Does this end at the origin "<<isCircling(str);
   return 0;
}
