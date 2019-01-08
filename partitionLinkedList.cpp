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
    ListNode* partition(ListNode* head, int x) {
        //maintain two linked lists, smaller one and bigger one
        //for smaller one, we use tail insert
        //for bigger one (>=), we use also tail insert
        //finally, we combine two lists
        ListNode* p1=NULL, *p2=NULL, *p = head, *shead=NULL, *bhead=NULL;
        while (p)
        {
            if (p->val<x)
            {
                if (!shead)
                {
                    shead = p;
                    p1 = shead;
                    // p1->next = NULL;
                }
                else
                {
                    p1->next = p;
                    p1 = p;
                }
            }
            else
            {
                if (!bhead)
                {
                    bhead = p;
                    p2 = bhead;
                    // p2->next = NULL;
                }
                else
                {
                    p2->next = p;
                    p2 = p;
                }
            }
            p = p->next;
            if (p1)
                p1->next = NULL;
            if (p2)
                p2->next = NULL;
        }
        if (!shead)
            head = bhead;
        else
        {
            p1->next = bhead;
            head = shead;
        }
        return head;
    }
};
