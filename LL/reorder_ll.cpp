  ListNode* findMiddle(ListNode* head){
        ListNode* fast=head;
        ListNode* slow=head, *prev=nullptr;
        while(fast and fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        return slow;
    }

    ListNode* mergeLL(ListNode* h1,ListNode* h2){
        ListNode* temp1=h1;
        ListNode* temp2=h2;
        while(temp1){
            ListNode* nxtNode1=temp1->next;
            ListNode* nxtNode2=temp2->next;
            temp1->next=temp2;
            if(nxtNode1) temp2->next=nxtNode1;
            temp1=nxtNode1;
            temp2=nxtNode2;
        }

        return h1;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp){
            ListNode* nxtNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxtNode;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head or !head->next) return;
        ListNode* middleNode=findMiddle(head);
        ListNode* lastHead=reverseLL(middleNode);
        mergeLL(head,lastHead);
        return;

    }
