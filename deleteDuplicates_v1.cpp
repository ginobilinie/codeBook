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
        ListNode *p1, *p2;
        
        p1 = head;
        int cnt;
        while(p1)
        {
            p2 = p1;
            cnt = 0;
            while ((p1=p1->next)&&p2->val==p1->val) cnt++;
            if (cnt)
                p2->next = p1;
        }
        return head;
    }
};
