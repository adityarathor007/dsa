    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int size=0;
        ListNode* temp=head;
        ListNode* tail=head;
        while(temp){
            size+=1;
            temp=temp->next;
            if(temp) tail=temp;
        }

        k=k%size;
        if(k==0) return head;

        temp=head;
        ListNode* newHead;

        while(k!=size){
            k+=1;
            if(k==size){
                newHead=temp->next;
                temp->next=nullptr;
            }
            temp=temp->next;
        }

        tail->next=head;
        return newHead;



    }
