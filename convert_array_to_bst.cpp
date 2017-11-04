#include <iostream>
#include <array>
#include <stack>

using namespace std;
struct Node
{
   int val;
   Node* left;
   Node* right;
};

Node* convertArrayToBSTRecurse(array<int> preOrderNodes,int low,int high)
{
   if(low<=high)
   {
      Node* root = new Node();
      root->data = preOrderNodes[low];
      int i = low;
      for(;i<high;++i)
         if(preOrderNodes[i]>preOrderNodes[low])
	     break;
      root->left = convertArrayToBSTRecurse(preOrderNodes,low+1,i-1);
      root->right = convertArrayToBSTRecurse(preOrderNodes,i,high);
      return root;
   }
   return nullptr;
}

Node* convertArrayToBST(array<int> preOrderNodes)
{
    Node root;
    root.val = preOrderNodes[0];
    root.left = nullptr;
    root.right = nullptr;
    stack<int> var;
    var.push(root);
    for(int i=1;i<preOrderNodes.size();++i)
    {
        Node* ptr = nullptr;
        while(preOrderNodes.size()!=0 && preOrderNodes[i] > var.top())
	     ptr=var.pop;
  	if(ptr == nullptr)
        {
            Node temp = var.top();
            temp.left = preOrderNodes[i];
            var.pop();
            var.push(temp);
        }
        else
        {
            ptr->right = preOrderNodes[i];
            var.push(ptr);
        }
    } 
}

int main()
{
  return 0;
}

