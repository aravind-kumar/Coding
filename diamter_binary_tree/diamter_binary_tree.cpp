#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

struct Node
{
     typedef shared_ptr<Node> NodePtr;
     Node()
     {
         data = 0;
         left = nullptr;
         right = nullptr;
     }
     Node(int num)
     {
         data = num;
         left = nullptr;
         right = nullptr;
     }
      
     Node(int num,NodePtr left,NodePtr right)
     {
         data = num;
         this->left = left;
         this->right = right;
     }

     int getNum()
     {
        return data;
     }
      
      void addLeft(int num)
      {
         if(left!=nullptr)
         {
            (left->left).reset(new Node(num));
         }
      }
      void addRight(int num)
      {
         if(right!=nullptr)
         {
            (right->right).reset(new Node(num));
         }
      }

      int data;
      NodePtr left;
      NodePtr right;
};

class BinaryTree
{
   private: 
      Node::NodePtr root;
   public:
      void insert(int num)
      { 
          if(root==nullptr)
          {
             root.reset(new Node(num));
          }
      }
            
      int getHeight(Node::NodePtr input,int& ans)
      {
          if(input==nullptr)
             return 0;
          int lHeight = getHeight(input->left,ans);
          int rHeight = getHeight(input->right,ans);
          ans = max(ans,lHeight+rHeight+1);
          return lHeight + rHeight + 1;
      }
     
      int getDiamter()
      { 
         int sum=0;
         getHeight(root,sum);
         cout<<sum;
         return sum;
      }
      shared_ptr getRoot() { return root;} 
};

int main()
{
   BinaryTree newTree;

   newTree.insert(1);
   Node::NodePtr rootNode = newTree.getRoot();
   root.addLeft(2);
   root.addRight(3);

   return 0;
}
