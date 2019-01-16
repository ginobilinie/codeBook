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
    bool hasCycle(ListNode *head) {
        //this version using double skip and single skip to solve it.
        ListNode *p1=head, *p2=head;
        bool flag = 0;
        while(p1&&p2)
        {
            p1 = p1->next;
            p2 = p2->next;
            if (p2)
                p2 = p2->next;
            if (p1==p2&&p2)
            {
                flag = 1;
                break;
            }
        
        }
        return flag;
    }
};
