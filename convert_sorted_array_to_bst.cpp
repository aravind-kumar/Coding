/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> nums) {
        if(nums.empty()) return nullptr;
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums,int i,int j) {
        if(nums.empty() || i<0 || j>nums.size() || i>j) return nullptr;
        int size = j+i;
        int mid = size/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums,i,mid-1);
        root->right = sortedArrayToBST(nums,mid+1,j);
        return root;
    }
};
