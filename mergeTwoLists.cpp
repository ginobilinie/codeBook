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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL)
            return l2;
        if (l2==NULL)
            return l1;
        ListNode* p0=l1;
        ListNode* p1=l1;
        ListNode* p2 = l2;
        ListNode* tmp;
        int flag = 0;
        while (p1 && p2)
        {
            if (p1->val<p2->val)
            {
                p0 = p1;
                p1 = p1->next;
            }
            else
            {
                tmp = p2->next;
                if (p1==p0)
                {
                    p2->next = p0;
                    //if (flag==0)
                    //{
                     //   l1 = p2; 
                     //   flag = 1;
                    //}
                    l1 = p2;
                    p0 = p2;
                    p1 = p2;
                }
                else
                {
                    p2->next = p1;
                    p0->next = p2; 
                    p0 = p0->next;
                }

                p2 = tmp;
            }
        }
        if (p2)
        {
            if (p0)
                p0->next = p2;
            else
                p0 = p2;
        }
        return l1;
    }
};
