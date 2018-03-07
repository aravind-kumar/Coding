#include <iostream>
#include <vector>

struct ListNode {
   int val
   ListNode* next;
   ListNode(int val) {
      this->val = val;
      next = nullptr;
   }

};

ListNode* deleteDuplicates(ListNode* head) {
        if(head!=nullptr && head->next != nullptr) {
            auto pre = head,current = head->next;
            
            while(pre!=nullptr && current!=nullptr) {      
                if(pre->val == current->val) {
                    pre->next = pre->next->next;
                    current = pre->next;
                } else {
                    pre = current;
                    current = current->next;    
                }   
            }
            
        }
        return head;
        
    }

int main() {



    return 0;
}
