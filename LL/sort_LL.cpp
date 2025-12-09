ListNode* mergeHeads(ListNode* h1, ListNode* h2){
        ListNode dummy;
        ListNode* tail = &dummy;

        while (h1 && h2) {
            if (h1->val <= h2->val) {
                tail->next = h1;
                h1 = h1->next;
            } else {
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }

        tail->next = h1 ? h1 : h2;
        return dummy.next;
    }

    ListNode* findMidNode(ListNode* sNode,ListNode* eNode){
        ListNode* fast=sNode;
        ListNode* slow=sNode;
        while(fast!=eNode and fast->next!=eNode){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* mergeSort(ListNode* sNode,ListNode* eNode){
        if(sNode==eNode) return sNode;

        ListNode* midNode=findMidNode(sNode,eNode);
        ListNode* midNodeNext=midNode->next;
        midNode->next=nullptr;

        ListNode* h1=mergeSort(sNode,midNode);
        ListNode* h2=mergeSort(midNodeNext,eNode);

        return mergeHeads(h1,h2);

    }

    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        ListNode* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        return mergeSort(head,temp);

    }
