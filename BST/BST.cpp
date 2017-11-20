#include "BST.h"

Node* BST::getInorderSucessor(Node* root)
{
    if(root!=NULL && root->right!=NULL)
    {
        Node* rightNode = root->right;
        while(rightNode->left != NULL)
        {
            rightNode = rightNode -> left;
        }
        return rightNode;
    }
    return NULL;
}

Node* BST::getInorderPredessor(Node* root)
{
    if (root != NULL && root->left !=NULL)
    {
        Node* leftNode = root->left;
        while(leftNode->right != NULL)
	{
 	    leftNode = leftNode->right;
     	}
        return leftNode;
    }
    return NULL;
}

Node* BST::deleteNode(Node* root,int key)
{
   if(root==NULL)
   {
       return NULL;
   }
   else if (key < root->num)
   {
        root->left = deleteNode(root->left,key);
   }
   else if (key > root->num)
   {
       root->right = deleteNode(root->right,key);
   }
   else
   {
       if(root->right==NULL)
       {
           Node* leftSubTree = root->left;
           delete root;
           return leftSubTree;
       }
       else if (root->left==NULL)
       {
           Node* rightSubTree = root->right;
           delete root;
           return rightSubTree;
       }
       Node* SucessorNode = getInorderSucessor(root);
       if(SucessorNode != NULL)
       {
          swap(SucessorNode->num,root->num);
          root->right = deleteNode(root->right,SucessorNode->num);
       }
       Node* PredissorNode = getInorderPredessor(root);
       if(PredissorNode != NULL)
       {
	  swap(PredissorNode->num,root->num);
          root->left = deleteNode(root->left,SucessorNode->num);
       }
       
   }
   return root;
}

void BST::InorderTraversal(Node* root,function<void(Node*)> fun)
{
   if(root != NULL)
   {
       InorderTraversal(root->left,fun);
       fun(root);
       InorderTraversal(root->right,fun);
   }
}

void BST::PostOrderTraversal(Node* root,function<void(Node*)> fun)
{
    if(root!=NULL)
    {
	PostOrderTraversal(root->left,fun);
	PostOrderTraversal(root->right,fun);
	fun(root);
    }
}

void BST::PreOrderTraversal(Node* root,function<void(Node*)> fun)
{
    if(root!=NULL)
    {
       fun(root);
       PreOrderTraversal(root->left,fun);
       PreOrderTraversal(root->right,fun);
    }
}

void BST::InorderTraversal(function<void(Node*)> fun)
{
   InorderTraversal(m_root,fun);
}

void BST::PostOrderTraversal(function<void(Node*)> fun)
{
   PostOrderTraversal(m_root,fun);
}

void BST::PreOrderTraversal(function<void(Node*)> fun)
{
   PreOrderTraversal(m_root,fun);
}

Node* BST::insert(Node* root,int key)
{ 
    if(root==NULL)
    {
        return getNewNode(key); 
    }
    else if(key < root->num)
    {
         root->left = insert(root->left,key);
    }
    else if(key > root->num)
    {
         root->right = insert(root->right,key);
    }
    return root;
}

Node* BST::search(Node* root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if (root->num == key)
    {
         return root;
    }
    else if (key < root->num)
    {
        return search(root->left,key);
    }
    else 
        return search(root->right,key);
}

bool BST::search(int key)
{
    Node* result = search(m_root,key);
    return (result!=NULL);
}

void BST::insert(int key)
{
    m_root=insert(m_root,key); 
}

void BST::deleteNode(int key)
{
   m_root=deleteNode(m_root,key); 
} 
