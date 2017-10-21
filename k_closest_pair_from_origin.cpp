#include <iostream>
#include <assert.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

struct Point
{
   int x,y;
};


int getDistance(Point A,Point B)
{
   return (sqrt(pow((B.x-A.x),2) + pow((B.y-B.x),2)));

}

bool distanceFromCompare(Point A,Point B)
{
    Point Origin={0,0};
    return (getDistance(A,Origin) < getDistance(B,Origin));
}

void GetNLowestElementsFromOrigin(vector<Point> inputVector,int n)
{
    partial_sort(inputVector.begin(),inputVector.begin()+n,inputVector.end(),distanceFromCompare);
    for_each(inputVector.begin(),
	     inputVector.begin()+n,
	     [](Point n) 
	     {
 		  cout<<"\n x:"<<n.x<<"y: "<<n.y;
       	     });	
}

int main()
{

  return 0;
}
