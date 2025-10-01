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

class myComparator{
    public:
        bool operator() (const ListNode* p1, const ListNode* p2)
        {
            return p1->val > p2->val;
        }
    };


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,myComparator>pq;

        for(int i=0;i<lists.size();i++){
            // ListNode* temp=lists[i];
            // while(temp){
            //     pq.push(temp);
            //     temp=temp->next;
            // }

            // instead of storing the complete linked list store just the heads
            if(lists[i]){
                pq.push(lists[i]);
            }

        }

        ListNode* head=nullptr;


        while(!pq.empty()){
            ListNode* temp=pq.top();
            if(!head){
                head=temp;
            }
            pq.pop();
            if(temp->next){
                pq.push(temp->next);
            }

            if(pq.empty()){
                temp->next=nullptr;
            }
            else{
                temp->next=pq.top();
            }


        }

        return head;
    }
};
