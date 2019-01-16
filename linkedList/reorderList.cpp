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
    void reorderList(ListNode* head) {
        //a problem with head-in insert and tail-in 
        if (head==NULL)
            return;
        
        //we first determine the middle pointer
        ListNode *p1 = head, *p2=head, *mid, *tmp, *tt, *p, *head1;
        while (p1&&p2)
        {   
            p = p1;
            p1 = p1->next;  
            p2 = p2->next;
            if (p2)
                p2 = p2->next;
            if (p2&&!p2->next)
                break;
        }
        p->next = NULL;
        mid = p1;
        
        //reverse the 2nd list
        p = mid;
        head1 = NULL;
        while (p)
        {
            tmp = p->next;
            p->next = head1;
            head1 = p;
            p = tmp;
        }
        //at this time, head1 is the reverse of the 2nd list
        p = head;
        p1 = head1;
        while (p&&p1)
        {
            tmp = p->next;
            tt = p1->next;
            p->next = p1;
            if (tmp)
                p1->next = tmp;
            p1 = tt;
            p = tmp;
        }
        
    }
};
