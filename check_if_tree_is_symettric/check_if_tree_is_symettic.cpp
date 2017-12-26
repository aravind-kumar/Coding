#include <iostream>
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


bool isSymetticHelper(Node* left,Node* right)
{
  if(left==nullptr && right==nullptr)
     return true;
  else if(left && right && left->data==right->data)
  {
     return isSymetticHelper(left->left,right->right) && isSymetticHelper(left->right,right->left); 
  }
  return false;

}
bool isSymettic(Node* root)
{
   return root!=nullptr && isSymetticHelper(root->left,root->right);
}

int main()
{
   Node* root = createNode(1);
   root->left = createNode(2);
   root->right = createNode(3);
   root->left->left = createNode(4);
   root->left->right = createNode(5);
   
   cout<<"\n Is Tree symettric"<<isSymettic(root); 

   return 0;
}
