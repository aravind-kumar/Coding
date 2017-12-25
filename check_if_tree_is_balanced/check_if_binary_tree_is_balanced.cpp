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
      int rheight = height(root->right);
      return max(lheight,rheight) + 1;
    }
    return 0;
}

Node* createNode(int data)
{
    Node* newdata = new Node;
    newdata->data = data;
    newdata->left = nullptr;
    newdata->right = nullptr;
    return newdata;
}

bool isBalanced(Node* root)
{
   if(root)
   {
      int lheight = height(root->left);
      int rheight = height(root->right);
      bool result = abs(lheight-rheight)<=1;
      return result && isBalanced(root->left) && isBalanced(root->right); 
   }
   return true;
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
