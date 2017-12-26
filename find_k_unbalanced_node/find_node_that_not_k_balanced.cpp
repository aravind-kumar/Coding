#include <iostream> 
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data)
{
    Node* newdata = new Node;
    newdata->data = data;
    newdata->left = nullptr;
    newdata->right = nullptr;
    return newdata;
}

typedef pair<Node*,int> NodeNumPair;

NodeNumPair getNodeNotKBalancedHelper(Node* n,int k)
{
   if(n==nullptr)
     return {nullptr,0};
   NodeNumPair left = getNodeNotKBalancedHelper(n->left,k);
   if(left.first)
       return left;
   NodeNumPair right = getNodeNotKBalancedHelper(n->right,k);
   if(right.first)
       return right;
   int total = left.second + right.second+1;
   if(abs(left.second-right.second) > k)
     return {n,total};

   return {nullptr,total};
}

Node* getNodeThatsNotKBalanced(Node* root,int k)
{
   return getNodeNotKBalancedHelper(root,k).first;
}

int main()
{
   int k;
   Node* root = createNode(1);
   root->left = createNode(2);
   root->right = createNode(3);
   root->left->left = createNode(4);
   root->left->right = createNode(5);
   cout<<"\n Enter the k balance";
   cin>>k;
   cout<<"\n The k balanced Node is"<<getNodeThatsNotKBalanced(root,k);
 
   return 0;
}
