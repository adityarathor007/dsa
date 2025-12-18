  ListNode* removeNthFromEnd(ListNode* head, int n) {
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;

        ListNode* temp=head;
        int size=0;
        while(temp){
            temp=temp->next;
            size+=1;
        }
        int start_i=size-n+1;
        int i=1;
        temp=head;
        ListNode* prev=nullptr;

        while(true){
            if(i==start_i){
                if(prev) prev->next=temp->next;
                else head=temp->next;
                temp=nullptr;
                break;
            }
            i+=1;
            prev=temp;
            temp=temp->next;

        }
        return head;

    }

    }
