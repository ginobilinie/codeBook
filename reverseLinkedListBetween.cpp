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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //we partition the lists into three parts
        //and we reverse the intermedia part by head-in insertion
        ListNode *tail0, *p1, *head1, *tail1, *head2, *p, *tmp;
        tail0 = head;
        p = head;
        int cnt = 1;
        if (m==n)
            return head;
        while (p&&cnt<m)
        {
            cnt++;
            tail0 = p;
            p = p->next;
        }
        head1 = p;
        tail1 = p;
        if (m<n)
        {
            p = p->next;            
        }
        int start = m;
        while (p&&m<n)
        {
            //head in
            m++;
            tmp = p->next;
            p->next = head1;
            head1 = p;
            p = tmp;
        }
        if (tail1)
            tail1->next = p;
        if (start==1)
            head = head1;
        else
            tail0->next = head1;

        return head;
        
    }
};
