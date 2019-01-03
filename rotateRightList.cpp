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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode* tmp = head;
        while (tmp)
        {
            len++;
            tmp = tmp->next;
        }
        if (len==0)
            return head;
        int pos = k%len;
        if (pos==0)
            return head;
        pos = len - pos;
        ListNode* p1=head, *phead;
        while(pos--)
        {
            tmp = p1;
            p1 = p1->next;
        }
        //return head;
        tmp->next = NULL;
        phead = p1;
        p1 = phead;
        while (p1->next)
        {
            p1 = p1->next;
        }
        p1->next = head;
        return phead;
    }
};
