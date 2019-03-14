class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 != nullptr || l2 != nullptr) {
            
            if(l1 == nullptr) return l2;
            if(l2 == nullptr) return l1;
            
            if(l1->val < l2->val) {
                ListNode* newNode = new ListNode(l1->val);
                newNode->next = mergeTwoLists(l1->next,l2);
                return newNode;
            } else {
                ListNode* newNode = new ListNode(l2->val);
                newNode->next = mergeTwoLists(l1,l2->next);
                return newNode;
            }
        }
        return nullptr;
    }
};
