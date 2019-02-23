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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.empty() || inorder.empty()) return nullptr;
        unordered_map<int,int> indexMap;
        for(int i=0;i<inorder.size();++i) {
            indexMap[inorder[i]] = i;
        }
        pair<int,int> startEnd = {0,inorder.size()-1};
        int start = 0;
        return buildTree(preorder,inorder,startEnd,indexMap,start);
    }
    
    TreeNode* buildTree(vector<int>& preorder,
                       vector<int>& inorder,
                       pair<int,int> startEnd,
                       unordered_map<int,int>& indexMap,
                       int& start) {
        if(startEnd.first > startEnd.second || startEnd.second < startEnd.first 
           || start < 0 || start >= inorder.size()) {
            return nullptr;
        }
        
        auto node = new TreeNode(preorder[start]);  
        int index = indexMap[preorder[start]];
        ++start;
        node->left = buildTree(preorder,inorder,{startEnd.first,index-1},indexMap,start); 
        node->right = buildTree(preorder,inorder,{index+1,startEnd.second},indexMap,start);
        return node;
    }
};

//We know that preorder is root,left,right and inorder is left,root,right 
// hence we know that the first element in preorder traversal is always root followed by other elementss.
// once we know the root we find the left and right subtree using inorder index map we created.
// on subsequent itreations the start is incremented and points the root of the left subtree in the preorder traveral.
// We use the same apporach as that of post-inorder but in that we started from the end and went to the righ first, in this 
// we start from 0 and go to the left first because of the traversal technique used.
