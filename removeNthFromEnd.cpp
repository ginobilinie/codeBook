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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* p0 = head;
        while(p0)
        {
            len++;
            p0 = p0->next;
        }
        int m = len - n;
        if (m==0)
        {
            head = head->next;
            return head;
        }
        p0 = head;
        ListNode* p1 = head;
        while(p0)
        {
            m--;
            if (m==0)
                break;
            p0 = p0->next;//locate at the one before the target item
        }
        if (p0->next)
        {
            p1 = p0->next;
            p0->next = p1->next;
        }
        else
            p0->next = NULL;
        return head;
    }
};
