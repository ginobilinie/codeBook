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
        ListNode *pa=headA, *pb=headB, *res = NULL;
        unordered_map<ListNode*,bool> mymap;
        while (pa&&pb)
        {
            if (pa==pb)
            {
                res = pa;
                break;
            }
            if (mymap.count(pa))
            {
                res = pa;
                break;
            }
            if (mymap.count(pb))
            {
                res = pb;
                break;
            }
            mymap[pa] = 1;
            mymap[pb] = 1;
            pa = pa->next;
            pb = pb->next;
        }
        while(pa)
        {
            if (mymap.count(pa))
            {
                res = pa;
                break;
            }
            pa = pa->next;
        }
        while(pb)
        {
            if (mymap.count(pb))
            {
                res = pb;
                break;
            }
             pb = pb->next;
        }
        return res;
    }
};
