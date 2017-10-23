#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;

typedef pair<int,bool> Node;
typedef unordered_map<int,vector<Node>> Graph;


void doTopologicalSort(Graph input,int src)
{
    if(input.find(src) != input.end())
    {
      remove_if(input[src].begin(),input[src].end(),
                [](Node givenNode) 
                { return givenNode.second;});

      for_each(input[src].begin(),input[src].end(),
 	       [&input,src](Node givenNode)
               {
                   replace(input[src].begin(),input[src].end(),
		           givenNode,
                           make_pair(givenNode.first,true));
                   doTopologicalSort(input,givenNode.first);
               });      
    }
    cout<<"\n"<<src;
}
    
int main()
{
   Graph g(10);
   Node n5_1(2,false);
   Node n5_2(0,false);
   Node n4_0(0,false);
   Node n4_1(1,false);
   Node n2_1(3,false);
   Node n3_2(1,false);
   vector<Node> Node5List={n5_1,n5_2};
   vector<Node> Node4List={n4_0,n4_1};
   vector<Node> Node2List={n2_1};
   vector<Node> Node3List={n3_2};
   g[2]=Node2List;
   g[3]=Node3List;
   g[4]=Node4List;
   g[5]=Node5List;
   doTopologicalSort(g,5);
   return 0;
}
