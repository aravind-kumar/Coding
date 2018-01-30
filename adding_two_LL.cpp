class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     
        ListNode* head=nullptr;
        ListNode* tail=head; 
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry)
        {
            int xVal = l1 == nullptr ? 0 : l1->val;
            int yVal = l2 == nullptr ? 0 : l2->val;
            int sum = xVal + yVal +carry;
            int finalVal = sum%10;
            carry = sum/10;
            
            //cout<<finalVal<<endl;
            if(head==nullptr)
            {
                head=new ListNode(finalVal);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(finalVal); 
                tail = tail->next;
                
            }
                   
            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
        }
        return head;
    }
};
