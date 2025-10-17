 ListNode* deleteMiddle(ListNode* head) {
    if(!head || !head->next) return NULL;
        ListNode* slow=head,*fast=head;
        ListNode* prev=NULL;

        while(fast and fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        prev->next=slow->next;
        delete(slow);
        return head;
 }
