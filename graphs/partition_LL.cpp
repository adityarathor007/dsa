/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

    ListNode* partition(ListNode* head, int x) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* greaterEqualHead,*lessTail;

        while(curr){
            if(curr->val>=x and !greaterEqualHead){
                greaterEqualHead=curr;
                lessTail=prev;
            }
            if(curr->val<x and greaterEqualHead){
                ListNode* nxtNode=curr->next;
                prev->next=nxtNode;
                curr->next=greaterEqualHead;
                if(lessTail){
                    lessTail->next=curr;
                }
                else{
                    head=curr; //no lessTail means this node will become the head
                }
                lessTail=curr;
                curr=nxtNode;
                continue; //prev will remain the same as node after was removed
            }
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
