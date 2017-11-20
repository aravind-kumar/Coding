#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMaxLength(vector<char> inputVector)
{
  //
  for(int i=1;i<=inputVector.size();) 
}

int main()
{
  //For simplicity have inputs as chars since its easy to represent number and
  // infinity as *.
  vector<char> inputVector={'1','2','3','4','*','*','*'}; 
  int maxLength = findMaxLenght(inputVector);
  return 0;
}


void DFS(Node src,vector<Node>& result)
{
  if(adjList.find(src) != adjList.end())
    {
      for(auto&& dstNode : adjList[src])
        {
          if(dstNode.isVisited() && dstNode.isReverseVisited())
            {
              continue;
            }
          else if(dstNode.isVisited() == false)
            {
              dstNode.markVisited();
              result.push_back(dstNode);
              DFS(dstNode,result);
            }
          else if (dstNode.isVisited() == true
                   &&
                   dstNode.reverseVisted() == false)
            {
              dstNode.markReverseVisited();
              result.push_back(dstNode);
            }
        }
    }
}
