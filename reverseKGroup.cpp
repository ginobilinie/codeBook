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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *frontNode4ThisGroup, *currNode, *endNode4ThisGroup;
        ListNode *prevEndNode4ThisGroup,*tmp;
        
        frontNode4ThisGroup = head;
        currNode = head;
        
        int len = 0;
        while (currNode)//compute the length
        {
            len++;
            currNode = currNode->next;
        }
        if (k==0)
            return head;
        if (k>len)
            return head;
        int groups = len/k;
        int remaining = len%k;
        
        currNode = head;
        head = NULL;
        for (int i=0; i<groups; i++)
        {
            endNode4ThisGroup = currNode;
            for (int j=0; j<k; j++)
            {
                if (currNode)
                {
                    if (currNode->next)
                    {
                        tmp = currNode->next;
                    }
                    currNode->next = frontNode4ThisGroup;//head-in insert
                    frontNode4ThisGroup = currNode;
                    currNode = tmp;
                }
            }
            if (head==NULL)
            {
                head = frontNode4ThisGroup;
                prevEndNode4ThisGroup = endNode4ThisGroup;
            }
            else
            {
                prevEndNode4ThisGroup->next = frontNode4ThisGroup;
                prevEndNode4ThisGroup = endNode4ThisGroup;
            }
        }
        
        if (remaining)
        {
            prevEndNode4ThisGroup->next = currNode;
            if (head==NULL)
                head = currNode;
        }
        else
            prevEndNode4ThisGroup->next =  NULL;
       return head;
    }
};
