#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

int height(Node* root)
{
    if(root)
    {
      int lheight = height(root->left);
      if(lheight == -1) return -1; 
      int rheight = height(root->right);
      if(rheight == -1) return -1; 
      if(abs(lheight-rheight) > 1) return -1;
      return max(lheight,rheight) + 1;
    }
    return 0;
}

bool isBalanced(Node* root)
{
   return height(root) != -1;
}

int main()
{
   Node* root = createNode(1);
   root->left = createNode(2);
   root->right = createNode(3);
   root->left->left = createNode(4);
   root->left->right = createNode(5);

   cout<<isBalanced(root)<<"\n";

   root->right->left = createNode(6);
   root->right->right = createNode(7);

   cout<<isBalanced(root);
   
   return 0;
}
