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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       ListNode* rightMostLess=nullptr;
        ListNode* leftMostGreaterEqual=nullptr;
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp){
            int val=temp->val;
            ListNode* nxtNode=temp->next;
            ListNode* curr=temp;
            if(val>=x){
                if(!leftMostGreaterEqual) leftMostGreaterEqual=temp;
                prev=curr; //only update prev when the node is not removed
            }
            else{
                if(!leftMostGreaterEqual){
                    rightMostLess=temp;
                    prev=curr; //same here also prev needs to be updated
                }
                else{
                    if(prev) prev->next=nxtNode;
                    if(rightMostLess) rightMostLess->next=temp;
                    temp->next=leftMostGreaterEqual;
                    rightMostLess=temp;
                    if(leftMostGreaterEqual==head) head=rightMostLess;
                }
            }
            temp=nxtNode;
        }
        return head;
    }
};
