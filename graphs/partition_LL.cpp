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
        ListNode* lastSmallest=nullptr,*firstGreatest=nullptr;
        ListNode* temp=head,*prev=nullptr;

        while(temp){
            // cout<<temp->val<<endl;
            if(temp->val<x){
                if(!firstGreatest){
                    lastSmallest=temp;
                    prev=temp;
                    temp=temp->next;
                }
                else{
                    ListNode* nxtNode=temp->next;
                    if(!lastSmallest) head=temp;
                    else lastSmallest->next=temp;

                    lastSmallest=temp;
                    temp->next=firstGreatest;
                    prev->next=nxtNode;
                    temp=nxtNode;
                }

            }

            else{
                if(!firstGreatest){
                    firstGreatest=temp;
                }
                prev=temp;
                temp=temp->next;
            }
        }

        return head;
    }
};
