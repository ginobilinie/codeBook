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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p0, *p1, *p2;
        // p0 = head;
        int cnt = 0;

        p1 = head;
        p0 = head;
        while (p1)
        {
            p2 = p1;
            cnt = 0;
            while ((p1=p1->next)&&p2->val==p1->val) cnt++;
            if (cnt)
            {
                if (p2==head)
                {
                    head = p1;
                    p0 = p1;
                }
                else
                {
                    p0->next = p1;
                    // p1 = p2;                       
                }
            
            }
            else
            {
                p0 = p2;
              // continue;  
            }
        }
        return head;
    }
};
