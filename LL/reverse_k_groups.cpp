 ListNode* reverseKGroup(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;

        while(temp){
            size+=1;
            temp=temp->next;
        }

        int num_groups=size/k;
        int curr=0;
        int i=0;
        temp=head;
        ListNode* newHead=head,*prev=nullptr,*currTail=temp;
        while(curr!=num_groups){
            ListNode* prevHead=temp;
            while(i!=k){
                ListNode* nxtNode=temp->next;
                temp->next=prev;
                prev=temp;
                temp=nxtNode;
                i+=1;
            }
            if(curr==0) newHead=prev;
            else{
                currTail->next=prev; //can update currTail->next after rotation of the next list
                currTail=prevHead;
            }
            curr+=1;
            i=0;
        }
        currTail->next=temp;

        return newHead;
 }
