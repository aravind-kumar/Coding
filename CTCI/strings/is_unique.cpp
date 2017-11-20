#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

bool AreUniqueBitMap(vector<char>& inputVector)
{
     bitset<256> bitMap;
     
     for(auto&& character: inputVector)
     {
	if(bitMap[character])
	{
	    return false;	
	}
        bitMap.set(character,1);
     }
     return true;	
}

bool AreUniqueIter(vector<char>& inputVector)
{
	for(int i=0;i<inputVector.size();++i)
	{
		for(int j=i+1;j<inputVector.size();++j)
		{
		   if(inputVector[i] == inputVector[j])
		   {
		      return false;
		   }
		}
	}
	return true;
}

int main()
{
    vector<char> input;
    input.push_back('a');
    input.push_back('b');
    input.push_back('c');
    input.push_back('d');

    AreUniqueBitMap(input) ? 
    cout<<"\n Yes"  :
    cout<<"\n No"; 

     
    return 0;
}
