#include <iostream>
#include <vector>

using namespace std;

unsigned int GetRoot(vector<int>& input,unsigned int i)
{
   unsigned int targetNode = i;
   while(i != input[i])
   {
        input[i]=input[input[i]];
	i=input[i];
   } 
   return i;
}

unsigned int GetHeight(unsigned int rootIndex,vector<int>& sizes)
{
    return sizes[rootIndex];
}

void AddHeight(unsigned int rootIndex,unsigned int newHeight,vector<int>& sizes)
{
  sizes[rootIndex]+=newHeight;
}

void Connect(vector<int>& input,unsigned int i,unsigned int j,
	     vector<int>& sizes)
{
    if(! AreConnected(input,i,j))
    {
        unsigned int rootOfI = GetRoot(input,i);
        unsigned int rootOfJ = GetRoot(input,j);

        unsigned int heightOfRootI = GetHeight(rootOfI,sizes);
        unsigned int heightOfRootJ = GetHeight(rootOfJ,sizes);
        
       if(heightOfRootJ <= heightOfRootI)
       {
          input[j] = rootOfI;
          AddHeight(rootOfI,heightOfRootJ,sizes);
       }
       else
       {
          input[i] = rootOfJ;
          AddHeight(rootOfJ,heightOfRootI,sizes);
       }
   }
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
    vector<unsigned int> heights(num,1); 
    
    return 0;
}
