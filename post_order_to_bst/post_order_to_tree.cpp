#include <iostream>
#include <vector>

using namespace std;

// This is same as preorder the only trick here is that we iterate from the back because that's where we have the root
// ideal preorder notation is left,right,root
// So we iterate from the back and since the next element to root is right we first set right followed by left.
// When compared to preorder where we had root,left,right 
// We iterate from the beginning and since the next element that occurs is left followed by right
// We first set left and then right

// At every iteration we set the left and right nodes wrt to the given key as the nodes in the range of min,key and key,max
// but for the next iteration we also need to update the key
// the new would be the next number in the vector (preorder) or previous number (postorder)
// We have to stop the recursion once the index reaches either size() (preorder) or -1(postorder)
// Hence we pass the index as refference since we want the iteration to stop once that happens

struct node {
     int data;
     node *left,*right;
     node(int data) {
         this->data = data;
         left = right = nullptr; 
     }
};

typedef pair<int,int> range;
node* postOrderToBST(vector<int> nums,int& index,int key,range numRange) {

      if (index>=0) {

         node* root = nullptr;
         if (key > numRange.first && key < numRange.second) {
             root = new node(key);
             index--;
             if(index >= 0) {
                 root->right = postOrderToBST(nums,index,nums[index],{key,numRange.second}); 
                 root->left = postOrderToBST(nums,index,nums[index],{numRange.first,key});
             } 
         }
         return root;
      }
      return nullptr;
}

void printInorder(node* root) {

     if(root!=nullptr) {
        printInorder(root->left);
        cout<<root->data<<" ";
        printInorder(root->right);
     }
}

node* postOrderToBST(const vector<int>& nums) {

    if(!nums.empty()) {
       int startIndex = nums.size()-1;
       range numRange = {INT_MIN,INT_MAX};
       return postOrderToBST(nums,startIndex,nums.front(),numRange);
    }
    return nullptr;
}

int main() {

    vector<int> nums = {1, 7, 5, 50, 40, 10};
    printInorder(postOrderToBST(nums));

    return 0;
}
