void reverseGroup(ListNode* start,ListNode* end){
        ListNode* prev=nullptr;
        ListNode* temp=start;
        while(temp!=end){
            ListNode* nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ch=head;
        ListNode* prev=nullptr;
        while(ch){
            ListNode* ct=ch;
            int cnt=0;
            while(ct and cnt!=k-1){
                ct=ct->next;
                cnt+=1;
            }

            if(cnt!=k-1 or !ct) break;
            ListNode* nxt=ct->next;

            reverseGroup(ch,nxt);

            if(!prev) head=ct;
            else prev->next=ct;
            ch->next=nxt;
            prev=ch;
            ch=ch->next;

        }
        return head;
    }
