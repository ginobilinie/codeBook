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
    ListNode* sortList(ListNode* head) {
        if (!head||!head->next)
            return head;
        //now we find the mid pointer
        ListNode* slow = head, *tail, *fast = head, *res;
        while (slow&&fast)
        {
            tail = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            if (!fast||!fast->next)
                break;
        }
        tail->next = NULL;//the first list's end points to NULL
        res = merge(sortList(head),sortList(slow));
        return res;
    }
    
    //merge two sorted list
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode *newHead=NULL, *tail, *p1=l1, *p2=l2,*tmp=NULL, *tp1=NULL, *tp2=NULL;
        newHead = p1;
        tail = newHead;
        while (p1&&p2)
        {
            tmp = NULL;
            while (p1&&p1->val<p2->val)
            {
                tmp = p1;
                p1 = p1->next;
            }
            if (tmp)
                tail = tmp;
            //if (p1)
             //   tp1 = p1->next;
            tp2 = p2->next;
            if (p1==newHead)
            {
                p2->next = newHead;
                newHead = p2;
                p1 = newHead;
            }
            else
            {
                if (tail)
                {
                    p2->next = tail->next;
                    tail->next = p2;
                    tail = p2;
                }
            }
            //p1 = tp1;
            p2 = tp2;
        }
        if (p2)
            tail->next = p2;
       
        return newHead;
    }
};
