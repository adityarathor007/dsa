int pairSum(ListNode* head){
    ListNode* slow=head;ListNode* fast=head;
    //finding the middle node
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* prev=NULL;

    //reverse the second half
    while(slow){
        ListNode* nextnode=slow->next;
        slow->next=prev;
        prev=slow;
        slow=nextnode;  
    }
    
    //calculating the twin sum
    int maxsum=0;
    while(prev){
        int sum=head->val + prev->val;
        maxsum=max(maxsum,sum);
        head=head->next;
        prev=prev->next;
    }
    return maxsum;
}