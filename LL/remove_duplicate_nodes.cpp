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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* prev=NULL;
        while((head and head->next and head->val==head->next->val) or (prev and head and prev->val==head->val)){
            prev=head;
            head=head->next;
        }

        if(!head) return head;
        ListNode* temp=head->next;
        prev=head;

        while(temp){
            ListNode* prev_1=NULL;
            while((temp and temp->next and temp->val==temp->next->val) or (prev_1 and temp and  prev_1->val==temp->val)){
                prev_1=temp;
                temp=temp->next;
            }

            prev->next=temp;
            prev=temp;
            if(temp) temp=temp->next;

        }

        return head;

    }
};
