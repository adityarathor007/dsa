
//  * Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *a = new ListNode(-1);
        ListNode *curr = a;
        int i = 1;
        while (i < n + 1)
        {
            if (i == n)
            {
                curr->next = head->next;
            }
            else
            {
                curr->next = head;
            }

            head = head->next;
            curr = curr->next;
            i++;
        }
        return a->next;
    }
};