#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <algorithm>

using namespace std;

typedef unordered_map<char,int> characterCountMap;

void BuildCharacterMap(characterCountMap& map,string const& str1,
		       function<int(int,int)> const& function)
{
    for(auto&& character: str1)
    {
         if(map.find(character) != map.end())
         {
             map[character]=function(map[character],1);
         }
         else
	 {
            pair<char,int> newPair(character,1);
            map.insert(newPair);
         }
    }
}

//Look at const refference
//Look at double reffernce &&

void PrintMap(characterCountMap& characterCount)
{
   for(auto&& element : characterCount)
   {
        cout<<"\n Key is :" << element.first;
        cout<<"\n Value is :" << element.second;
   }
}

bool isMapEmpty(characterCountMap& characterCount)
{
     bool result = all_of(characterCount.begin(),characterCount.end(),
			  [](pair<char,int> elem)
			  {
                               return (elem.second == 0);
                          });
     return result;
}

bool HaveSameCharCount(string const& str1,string const& str2)
{
   characterCountMap characterCount;
   BuildCharacterMap(characterCount,str1,plus<int>());
   BuildCharacterMap(characterCount,str2,minus<int>());
   if(isMapEmpty(characterCount))
   {
      return true;
   }
   return false;
   
}

bool isPerm(string& str1,string& str2)
{
   if((str1.length() == str2.length()) && (str1!=str2))
   { 
      if(HaveSameCharCount(str1,str2)) 
      { 
   	return true;
      }
   }   
   return false;
}

int main()
{
  string input1,input2;
  cout<<"\n Enter String 1: ";
  cin>>input1;
  cout<<"\n Enter string 2: ";
  cin>>input2;
  
  (isPerm(input1,input2)) ?
  cout<<"\n Yes" :
  cout<<"\n No"; 

 return 0;
}
