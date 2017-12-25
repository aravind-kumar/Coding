#include <iostream>
#include <functional>

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

Node* getInorderPredissor(Node* root)
{
   Node* current = root->left;
   while(current->right != nullptr && current->right != root)
      current = current->right;
   return current;
}

void doInorderTraversal(Node* root,function<void(int)> fn)
{
   Node* current = root;
   while(current != nullptr)
   {
      if(current->left == nullptr)
      {
         fn(current->data);
         current = current->right; 
      }
      else
      {
         auto pred = getInorderPredissor(current);
         if(pred->right == nullptr)
         {
            pred->right = current;
            current = current->left;   
         } 
         else
         {
             pred->right = nullptr;
             fn(current->data);
             current = current->right; 
         }
      }
   }

}

int main()
{
   Node* root = createNode(1);
   root->left = createNode(2);
   root->right = createNode(3);
   root->left->left = createNode(4);
   root->left->right = createNode(5);
   
   doInorderTraversal(root,[](int data) { cout<<data<<"\n";});   
   return 0;
}
