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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int temp;
        ListNode *l3 = new ListNode(0);
        ListNode *c = l3;
        int carry = 0;
        while (l1 || l2 || carry)
        {

            // l3->next=c;
            temp = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = temp / 10;
            c->next = new ListNode(temp % 10);
            c = c->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return l3->next;
    }
};