ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* c1=headA;
        ListNode* c2=headB;
        while (c1!=c2){
            c1=c1->next;
            c2=c2->next;
            if(c1==c2){
                return c1;
            }
            if(c1==nullptr){
                c1=headB;
            }

            if(c2==nullptr){
                c2=headA;
            }

        }
        return c1;
    }
