#include <iostream>


// The idea is to iterate through a level while forming the next levels next pointers
// once we get to the end of the current level iterate using the next pointers which were 
// formed in the previous iteration.Keep doing this until we reach the last level.

class Solution {
public:
    
    void connect(TreeLinkNode *root) {
     
            TreeLinkNode *current=root,*prev=nullptr,*next=nullptr;
            while(current!=nullptr && current->left!=nullptr && current->right!=nullptr) {
                if(prev==nullptr) {      
                    next = current->left;
                    prev = current->left;
                    prev->next = current->right;
                    
                } else {
                    prev->next = current->left;
                    prev = prev->next;
                    prev->next = current->right;
                }
                prev = prev->next;
                
                if(current->next == nullptr) {
                    current = next;
                    prev = nullptr;
                } else {
                    current = current->next;
                }
            }
        
    }
};

int main() {



    return 0;
}
