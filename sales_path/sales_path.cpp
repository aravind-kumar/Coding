#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Node
{
  int cost;
  vector<Node *> children;
  Node *parent;
  Node(int cost) {
    this->cost = cost;
  }
};

void getCheapestCostHelper(int& minSum,int sum,Node* root) {
  if(root!=nullptr) {
    sum+=root->cost;
    for(Node* node : root->children) {
      getCheapestCostHelper(minSum,sum,node);
    }
  }
  minSum = min(minSum,sum);
}

int getCheapestCost( Node *rootNode )
{
  int sum = 0,minSum = INT_MAX;
  getCheapestCostHelper(minSum,sum,rootNode);
  return minSum;
}



int main() {
  return 0;
}
