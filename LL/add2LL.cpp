 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        int carry=0;


        while(temp1!=nullptr||temp2!=nullptr||carry){
            int val1=temp1!=nullptr?temp1->val:0;
            int val2=temp2!=nullptr?temp2->val:0;
            int sum=val1+val2+carry;
            temp->next=new ListNode(sum%10);
            if(sum>=10){
                carry=1;
            }
            else{
                carry=0;
            }

            temp=temp->next;
            if(temp1!=nullptr){
                temp1=temp1->next;
            }
            if(temp2!=nullptr){
                temp2=temp2->next;
            }


        }

        return dummy->next;

    }
