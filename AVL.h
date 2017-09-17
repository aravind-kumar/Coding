#include "BST.h"

struct newNode : Node
{   
    int m_num;
    int m_height;
    newNode *left,*right;
};

class AVL : public BST
{
    void leftRotate(newNode* node)
    {
       newNode* temp = node->left;
       node->left = temp->right;
       temp->right = node;
    }
 
    void rightRotate(newNode* node)
    {
      newNode* temp = node->right;
      node->right = temp->left;
      temp->left = node;
    }

    newNode* getNewNode(int num,newNode* left=NULL,newNode* right=NULL)
    {
         newNode* Node = new newNode;
         Node->m_num = num;
         Node->m_left = left;
         Node->m_right = right;
         Node->m_height = 1; 
    }

    public:
    unsigned int getHeight(newNode* node)
    {
        if(node==NULL)
        {
             return 0;
        } 
        return node->height;
    }

    int GetBalanceFactor(newNode* node)
    {
        if(node != NULL)
        {
            int leftNodeHeight = node->left->height;
            int rightNodeHeight = node->right->height;
            return (leftNodeHeight-rightNodeHeight);
        }
    }

    newNode* insert(newNode* node,int key)
    {
       if (node == NULL)
       {
           return getNewNode(node);
       }
       else if (key < node->num)
       {
           node->left = insert(node->left,key);
       } 
       else if (key > node->num)
       {
           node->right = insert(node->right,key);
       }
       else
       {
           return node;
       }

       unsigned int leftSubtreeHeight = getHeight(node->left); 
       unsigned int rightSubtreeHeight = getHeight(node->right); 
       node->height = max(leftSubtreeHeight,rightSubtreeHeight) + 1;
        
       int balanceFactor = GetBalanceFactor(node);
       if(balanceFactor>1 && )
       {

       }
       else if (balanceFactor<1 && )
       {
           
       }
       else if(balanceFactor>1 && )
       {
          
       }
       else if (balanceFactor<1 && )
       {
           
       }

   }
      
    }
    
    newNode* deleteNode(newNode* node,int key)
    {
        
    }
    void insert(int key);
    void delete(int key);
};




