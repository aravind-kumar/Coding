#include <iostream>
#include <algorithm>
#include <utility>
#include <assert.h>

using namespace std;
template <typename T>
class BST
{
   private:
   class Node
   {
      T data;
      typdef shared_ptr<Node> NodePtr;
      NodePtr left;
      NodePtr right;
   };

   const NodePtr root;
   Node::NodePtr LCAHelper(NodePtr root,NodePtr node1,NodePtr node2) const
   {
      if(root==nullptr)
        return nullptr;
      else
      {
          NodePtr lTree = LCAHelper(root->left,node1,node2);
          NodePtr rTree = LCAHelper(root->right,node1,node2);
          if(lTree != nullptr && rTree != nullptr)
          {
              return root;
          }
          else if(lTree != nullptr)
          {
              return lTree;
          } 
          else if(rTree != nullptr)
          {
              return rTree;
          }
          return nullptr;
      }    
   } 
   public:
   Node::NodePtr getLCA(NodePtr node1,NodePtr node2) const
   {
      return LCAHelper(root,node1,node2);
   }
};

int main()
{

   return 0;
}
