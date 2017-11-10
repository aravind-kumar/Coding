#include <iostream>
#include <functional>

template <typname T>
void morrisTraversal(Node* root,function<void(T arg)> fn)
{
   Node* current=root;
   Node* pre;
   while(current != nullptr)
   {
      if(current->left == nullptr)
      {
          fn(current->data);
          current = current->right;
      } 
      else
      {
          pre = current->left;
          while(pre->right !=nullptr && pre->right != current) 
		pre=pre->right;
          if(pre->right == nullptr)
          {
             pre->right = current; 
             current = current->left;
          } 
          else
          { 
            pre->right = nullptr;
            fn(current->data);
            current = current->right; 
          }
      }

   }

}

int main()
{
   return 0;
}
