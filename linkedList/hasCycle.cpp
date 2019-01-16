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
        unordered_map<ListNode*, bool>  mymap;
        
        bool flag = 0;
        ListNode* p=head;
        while (p)
        {
            if (mymap.count(p))
            {
                flag = 1;
                break;
            }
            mymap[p] = 1;
            p = p->next;
        }
        return flag;
    }
};
