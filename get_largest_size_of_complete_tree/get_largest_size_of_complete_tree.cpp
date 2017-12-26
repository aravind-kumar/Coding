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

int getLargestCompleteTreeSize(Node* root,int& maxSize)
{
   if(root!=nullptr)
   {
       int lheight = getLargestCompleteTreeSize(root->left,maxSize);
       int rheight = getLargestCompleteTreeSize(root->right,maxSize);
       
       if(lheight==2 && rheight==2)
         maxSize=max(maxSize,lheight+1);

       return max(lheight,rheight)+1;
   }
   return 0;

}
int getLargestCompleteTree(Node* root)
{
   int maxSize=0;
   getLargestCompleteTreeSize(root,maxSize);
   return maxSize;
}

int main()
{
   Node* root = createNode(1);
   root->left = createNode(2);
   root->right = createNode(3);
   root->left->left = createNode(4);
   root->left->right = createNode(5);
   root->right->left = createNode(4);
   root->right->right = createNode(5);
 
   cout<<"\n The largest complete tree is "<<getLargestCompleteTree(root);
   return 0;
}
