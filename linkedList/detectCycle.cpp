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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> mymap;
        ListNode* p = head;
        while(p)
        {
            if (mymap.count(p))
            {
                return p;
                break;
            }
            mymap[p] = 1;
            p = p->next;
        }
        return NULL;
    }
};
