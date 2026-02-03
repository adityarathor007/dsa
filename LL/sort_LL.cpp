ListNode* findMiddleNode(ListNode* head){
        ListNode* fast=head,*slow=head;
        while(fast->next and fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

ListNode* mergeLL(ListNode* h1,ListNode* h2){
    ListNode* dummy=new ListNode();
    ListNode* temp=dummy;
    while(h1 and h2){
        int v1=h1->val;
        int v2=h2->val;
        if(v1<=v2){
            temp->next=new ListNode(v1);
            h1=h1->next;
        }
        else{
            temp->next=new ListNode(v2);
            h2=h2->next;
        }
        temp=temp->next;
    }

    if(h1) temp->next=h1;
    if(h2) temp->next=h2;

    return dummy->next;

}

ListNode* sortList(ListNode* head) {
    if(!head or !head->next) return head;

    ListNode* midNode=findMiddleNode(head);
    ListNode* nxtNode=midNode->next;
    midNode->next=nullptr;

    ListNode* h1=sortList(head);
    ListNode* h2=sortList(nxtNode);

    return mergeLL(h1,h2);

}
