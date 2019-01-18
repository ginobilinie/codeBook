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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa=headA, *pb=headB, *res=NULL;
        while(pa!=pb)
        {
            if (pa)
                pa = pa->next;
            if (pb)
                pb = pb->next;
            if (!pa&&!pb)
            {
                res = NULL;
                break;
            }
            if (!pa) pa = headB;
            if (!pb) pb = headA;
        }
        res = pa;
        return res;
    }
};
