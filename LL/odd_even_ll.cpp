ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* temp=head;
        ListNode* evenHead=nullptr;
        bool isOdd=true;
        while(!isOdd or (temp->next and temp->next->next)){
            ListNode* nxtNode=temp->next;
            temp->next=nxtNode->next;
            if(!evenHead) evenHead=nxtNode;
            temp=nxtNode;
            isOdd=!isOdd;
        }

        if(evenHead) temp->next=evenHead;
        return head;

    }
