#include <iostream>
#include <array>
#include <string>

using namespace std;
 
typedef array<char,200> charArray;

void shiftArray(charArray input,const unsigned startPos,const unsigned shiftBy)
{
    if(shiftBy)
    {
        if(shiftBy == 1)
	{
            char temp = input[startPos];
            int i;
            for(i = startPos;input[i]!='\0';++i)
            {
                 swap(input[i],temp);
            }
            swap(input[i],temp);
            swap(input[i+1],temp);
        }
        else
        {
            shiftArray(input,startPos+1,shiftBy-1);
        }
    }
     
}
 
void replace(charArray input,
	     char searchChar,
	     string replaceString)
{
    unsigned int replaceStringLength = replaceString.length();
    
    for(int i=0;i<input[i]!='\0';)
    {
        if(input[i]==searchChar)
	{
            shiftArray(input,i,replaceStringLength);
            for(auto&& character : replaceString)
	    {
              input[i]=character;
              ++i; 
            }  
        }
        else
	{
             ++i;
	}
         
    }
}

int main()
{
    charArray input;
    cout<<"\n Enter the string ";
    cin>>input;
    replace(input,' ',"%20");
    cout<<input; 
    return 0;
}
