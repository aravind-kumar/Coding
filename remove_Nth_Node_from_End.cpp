class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *current=head,*runner = head;
        while(n--) current = current->next;
        
        if(current != nullptr) {
            while(current->next != nullptr) {
                runner = runner->next;
                current = current->next;
            }   
        } else {
            ListNode* ans = head->next;
            head->next = nullptr;
            delete head;
            return ans;
        }
        ListNode* temp =runner->next;
        runner->next = temp->next;
        delete temp;
        
        return head;
    }
};
