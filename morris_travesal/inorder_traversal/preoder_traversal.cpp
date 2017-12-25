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

void doPreOrderTraversal(Node* root,function<void(int)> fn)
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
         Node* pred = getInorderPredissor(current);
         if(pred->right == nullptr)
         {
             pred->right = current;
             fn(current->data);
             current = current->left;
         }  
         else
         {
            pred->right = nullptr;
            current=current->right; 
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
 
   root->right->left = createNode(6);
   root->right->right = createNode(7);
 
   root->left->left->left = createNode(8);
   root->left->left->right = createNode(9);
 
   root->left->right->left = createNode(10);
   root->left->right->right = createNode(11); 
   
   doPreOrderTraversal(root,[](int data) { cout<<data<<"\n";});    
   return 0;
} 
