/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
        unordered_map<RandomListNode*, RandomListNode*> mymap;
        RandomListNode* newhead, *p, *newp, *tmp, *newtail;
        newhead = new RandomListNode(head->label);
        mymap[head] = newhead;
        p = head->next;
        newtail = newhead;
        while(p)//scan for next pointers
        {
            newp = new RandomListNode(p->label);
            mymap[p] = newp;
            newtail->next = newp;
            newtail = newp;
            p = p->next;
        }
        
        p=head;
        newp = newhead;
        while(p)//scan again for random pointers
        {
            if (!p->random)
            {
                newp->random = NULL;
            }
            else if (mymap.count(p->random))
            {
                newp->random = mymap[p->random];
            }
            // else//create a new one
            // {
            //     //somethingwrong
            // }
            p = p->next;
            newp = newp->next;
        }
        return newhead;
    }
};
