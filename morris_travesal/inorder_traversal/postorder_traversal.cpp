#include <iostream>
#include <list>
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

Node* getInorderSucesssor(Node* root)
{
   Node* current = root->right;
   while(current->left!=nullptr && current->left!=root)
        current=current->left;
   return current;
}

void doPostOrderTraversal(Node* root,function<void(int)> fn)
{
    list<int> nodes;
    Node* current = root;
    while(current != nullptr)
    {
      if(current->right == nullptr)
      {
          fn(current->data);
          current = current->left;
      } 
      else
      {
         Node* suc = getInorderSucesssor(current);
         if(suc->left == nullptr)
         {
            suc->left = current;
            nodes.push_front(current->data);
            current = current->right;            
         } 
         else
         {
           suc->left = nullptr;
           current = current->left;
         }
      }
    }
    for_each(nodes.begin(),nodes.end(),fn);
}

int main()
{
   Node* root = createNode(1);
   root->left = createNode(2);
   root->right = createNode(3);
   root->left->left = createNode(4);
   root->left->right = createNode(5);
 
   doPostOrderTraversal(root,[](int data) { cout<<data<<"\n";});   
   return 0;
}
