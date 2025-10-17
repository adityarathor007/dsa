  ListNode* oddEvenList(ListNode* head) {
if(!head || !head->next) return head;
        ListNode* prevOdd=head;
        ListNode* currEven=head->next;
        ListNode* leftMostEven=currEven;

        while(currEven and currEven->next){
            ListNode* currOdd=currEven->next;
            prevOdd->next=currOdd;
            currEven->next=currOdd->next;
            currOdd->next=leftMostEven;
            prevOdd=currOdd;
            currEven=currEven->next;
        }

        return head;
  }
