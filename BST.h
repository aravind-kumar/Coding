#include <iostream>
#include <functional>
#include <utility> 

using namespace std;

struct Node
{
   int num;
   Node *left,*right;
};

class BST
{
   private:
     Node* m_root;
   protected:
     Node* getNewNode(int num,Node* left=NULL,Node* right=NULL)
     {
         Node* newNode = new Node;
         newNode->num = num;
         newNode->left=left;
         newNode->right=right;
         return newNode;
     }
     void setRoot(Node* root)
     {
         m_root = root;
     }
     
     Node* insert(Node* root,int key); 
     Node* search(Node* root,int key);
     Node* deleteNode(Node* root,int key);
     Node* getInorderSucessor(Node* root);
     Node* getInorderPredessor(Node* root);
     void InorderTraversal(Node* root,function<void(Node*)> fun);
     void PostOrderTraversal(Node* root,function<void(Node*)> fun);
     void PreOrderTraversal(Node* root,function<void(Node*)> fun);

   public:
     
     BST(Node* rootNode=NULL):
               m_root(rootNode)
     {

     }
     void insert(int key);
     bool search(int key);
     void deleteNode(int key);
     void InorderTraversal(function<void(Node*)> fun);
     void PostOrderTraversal(function<void(Node*)> fun);
     void PreOrderTraversal(function<void(Node*)> fun);
     const Node* getRoot()
     {
          return m_root;
     }
};

