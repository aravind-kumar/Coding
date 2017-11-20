#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

enum Color {BLACK=0,WHITE,NONE};

typedef pair<int,Color> Node;
typedef unordered_map<int,vector<Node>> Graph;


bool isBipartite(Graph g,Node start,Color startColor)
{
   if(g.find(start.first) != g.end())
   {
      return all_of(g[start.first].begin(),
 	       g[start.first].end(),
               [&g,start,startColor](Node givenInput)
               {
                   if(givenInput.second == Color::NONE)
		   {
		       replace(g[start.first].begin(),
			       g[start.first].end(),
  			       givenInput,
 			       make_pair(givenInput.first,startColor));
                       Color nextColor = startColor==Color::BLACK ? Color::WHITE: Color::BLACK;
		       return  true && isBipartite(g,givenInput,nextColor);
		   }
                   if(givenInput.second == startColor)
                   {
                      return false;
                   } 
                   return true;
               });
   }
   return false;
}

int main()
{
   Graph g(10);
   Node n5_1(2,Color::WHITE);
   Node n5_2(0,Color::WHITE);
   Node n4_0(0,Color::WHITE);
   Node n4_1(1,Color::WHITE);
   Node n2_1(3,Color::WHITE);
   Node n3_2(1,Color::WHITE);
   vector<Node> Node5List={n5_1,n5_2};
   vector<Node> Node4List={n4_0,n4_1};
   vector<Node> Node2List={n2_1};
   vector<Node> Node3List={n3_2};
   g[2]=Node2List;
   g[3]=Node3List;
   g[4]=Node4List;
   g[5]=Node5List;
 
   cout<<isBipartite(g,n5_1,Color::BLACK);
   return 0;
}
