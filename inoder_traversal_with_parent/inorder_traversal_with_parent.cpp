#include <iostream>
#include <functional>

using namespace std;
struct Node 
{
   int data;
   Node* parent;
   Node* left;
   Node* right;
};


Node* createNode(int data)
{
   Node* newNode = new Node;
   newNode->data = data;
   newNode->left = nullptr;
   newNode->right = nullptr;
   newNode->parent = nullptr;
   return newNode;
}

void inorderTraversal(Node* root,function<void(int)> fn)
{
   bool leftVisited = false; // This is to know if the traversal back from child to parent comes from left or right;
   Node* current =  root;
   while(current)
   {
      if(!leftVisited)
          while(current->left != nullptr)
              current=current->left;
 
       leftVisited = true;

       fn(current->data);

       if(current->right != nullptr)
       {
           current = current->right;
           leftVisited = false;
       }
       else if(current->parent != nullptr)
       {
          Node* parent = current->parent;
          if(parent->left == current)
            current = parent;
          else
          {
             while(current!=nullptr && current->parent && current->parent->right == current)
                   current=current->parent;

             if(current->parent == nullptr)
                break;
             current = current->parent;
          }
       }
       else
          break;
   }
}

int main()
{
   Node* root = createNode(1);
   root->left = createNode(2);
   root->right = createNode(3);
   root->left->parent = root;
   root->right->parent = root;
//   root->left->left = createNode(4);
//   root->left->right = createNode(5);
//   root->left->left->parent = root->left;
//   root->left->right->parent = root->left;
 
   inorderTraversal(root,[](int data) { cout<<data<<"-->"; });
 
   return 0;
}
