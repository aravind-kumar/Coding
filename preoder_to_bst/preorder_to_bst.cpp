#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node *left,*right;
    node(int data) {
       this->data = data;
       left = right = nullptr;    
    }
};

typedef pair<int,int> range;
node* convertPreoderToBst(vector<int> nums,int& index,int key,range numRange) {

     if(index<nums.size()) {
        node* root = nullptr; 
        if(key>numRange.first && key < numRange.second) {
            root = new node(key); 
            ++index;
            if (index< nums.size()) {
                root->left = convertPreoderToBst(nums,index,nums[index],{numRange.first,key});
                root->right = convertPreoderToBst(nums,index,nums[index],{key,numRange.second});
            }
        }
        return root;
     } 
     return nullptr;
}

node* convertPreorderToBST(const vector<int>& nums) {
    if(!nums.empty()) {
        range numRange = {INT_MIN,INT_MAX};
        int start = 0;
        return convertPreoderToBst(nums,start,nums.front(),numRange);
    }
    return nullptr;
}

void printInorder(node* root) {
     if (root!=nullptr) {
         printInorder(root->left);
         cout<<root->data<<" ";
         printInorder(root->right);
     }
}

int main() {

    vector<int> input = {10, 5, 1, 7, 40, 50};
    printInorder(convertPreorderToBST(input));
    return 0;
}
