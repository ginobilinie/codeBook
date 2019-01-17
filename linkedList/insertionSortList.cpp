/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return head;
        ListNode* newHead=NULL, *p, *newp,*tmp, *newtmp;
        p = head;
        while (p)
        {
            tmp = p->next;
            if (!newHead||newHead->val>p->val)
            {
                p->next = newHead;
                newHead = p;
            }
            else
            {
                newp = newHead;
                while (newp&&newp->val<=p->val)//find the first item which is smaller than p
                {
                    newtmp = newp;
                    newp = newp->next;
                }
                p->next = newtmp->next;
                newtmp->next = p;
            }
            p = tmp;
        }
        return newHead;
    }
};
