#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> coord;
vector<coord> directions = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1}};

void printMaze(int x,int y,int numOfSegments)
{
   if(numOfSegments>0) {
      cout<<"X: "<<x<<"Y: "<<y<<endl;

      for(auto p : directions) {
         printMaze(x+p.first,y+p.second,numOfSegments-1);           
      }  
   }
}

int main()
{
   int x,y,segments;
   cout<<"\n Enter the start and end coordinates";
   cin>>x>>y;
   cout<<"\n Enter the number of segments";
   cin>>segments;  
   printMaze(x,y,segments);
   return 0;
}
