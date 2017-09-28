#include <iostream>
#include <vector>

using namespace std;

unsigned int GetRoot(vector<int>& input,unsigned int i)
{
   while(i != input[i])
   {
	i=input[i];
   } 
   return i;
}

void Connect(vector<int>& input,unsigned int i,unsigned int j)
{
    int rootOfI = GetRoot(input,i);
    input[j] = rootOfI;
}

bool AreConnected(vector<int>& input,
		  unsigned int i,
		  unsigned int j)
{
    return (GetRoot(input,i) == GetRoot(input,j));
}

int main()
{
    vector<int> nodes;
    unsigned int num;
    
    cout<<"\n Enter the number of nodes ";
    cin>>num;
    for(int i=0;i<num;++i)
    {	
       nodes.push_back(i);
    }

    return 0;
}
