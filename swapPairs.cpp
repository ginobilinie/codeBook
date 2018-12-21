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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev, *curr1, *curr2, *tmp;
        curr1 = head;

        int cnt = 0;
        if (!curr1)
            return NULL;
        if (!curr1->next)
            return head;
        curr2 = curr1->next;
        head = NULL;
        while(curr1 && curr2)
        {
            curr1->next = curr2->next;
            curr2->next = curr1;
            if (!head)
            {
                head = curr2;
                prev = curr1;
            }else
            {
                prev->next = curr2;   
                prev = curr1;
            }
            if (curr1)
                curr1 = curr1->next;
            if (curr1)
                curr2 = curr1->next;
        }
        return head;
    }
};
