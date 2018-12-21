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
    struct cmp
    {
        bool operator() (ListNode *a, ListNode* b)
        {
            //priority_queue判断的是!cmp, 所以是小到大的序要反过来
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> myqueue;
        int k = lists.size();
        for (int i=0; i<k; i++)
        {
            if (lists[i])
                myqueue.push(lists[i]);
        }
        ListNode* head=NULL, *prev, *curr;
        while (!myqueue.empty())
        {
            curr = myqueue.top();
            myqueue.pop();
            if (!curr)
                continue;
            if (curr->next)
                myqueue.push(curr->next);
            if (!head)
            {
                head = curr;
                prev = curr;
            }
            else
            {
                prev->next = curr;
                prev = curr;
            }
        }
        return head;
    }
};
