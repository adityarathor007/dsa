ListNode* findMiddle(ListNode* &head){
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=nullptr and fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

ListNode* mergeSortedList(ListNode* &left,ListNode* &right){
    ListNode* head=nullptr;
    ListNode* tail=nullptr;

    if(left->val<right->val){
        head=left;
        left=left->next;
    }
    else{
        head=right;
        right=right->next;

    }

    tail=head;

    while(left!=nullptr and right!=nullptr){
        if(left->val<right->val){
            tail->next=left;
            left=left->next;
        }
        else{
            tail->next=right;
            right=right->next;
        }
        tail=tail->next;

    }

    if(right!=nullptr){
        tail->next=right;
        tail=tail->next;
        while(tail!=nullptr){
            tail=tail->next;
        }
    }

    if(left!=nullptr){
        tail->next=left;
        tail=left->next;
        while(tail!=nullptr){
            tail=tail->next;
        }
    }

    return head;

}



ListNode* sortList(ListNode* head) {

    if(head==nullptr || head->next==nullptr) {
        return head;
    }

    ListNode* middlePtr=findMiddle(head);


    ListNode* leftHead=head;
    ListNode* rightHead=middlePtr->next;
    middlePtr->next=nullptr;


    leftHead=sortList(leftHead);
    rightHead=sortList(rightHead);


    head=mergeSortedList(leftHead,rightHead);

    return head;

}

