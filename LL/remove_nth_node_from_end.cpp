  ListNode* removeNthFromEnd(ListNode* head, int n) {
        // // M1 finding the size
        // ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(!head->next) return nullptr;

        // ListNode* temp=head;
        // int size=0;
        // while(temp){
        //     temp=temp->next;
        //     size+=1;
        // }
        // int start_i=size-n+1;
        // int i=1;
        // temp=head;
        // ListNode* prev=nullptr;

        // while(true){
        //     if(i==start_i){
        //         if(prev) prev->next=temp->next;
        //         else head=temp->next;
        //         temp=nullptr;
        //         break;
        //     }
        //     i+=1;
        //     prev=temp;
        //     temp=temp->next;

        // }
        // return head;

        // M2: Without finding the size (placing the head at that position at the starting so that dummy points to behind the node that is to be removed)
        ListNode* dummy=new ListNode(0,head);
        for(int i=0;i<n;i++){
            head=head->next; //placing the head at the position of (n+1) form begnining
        }
        // so that dummy points finally (size-n-1)
        while(head){
            head=head->next;
            dummy=dummy->next;
        }
        dummy->next=dummy->next->next;
        ListNode* res=dummy->next;

        delete dummy;
        return res;

    }

    
