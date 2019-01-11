/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head==NULL)
            return NULL;
        TreeNode *res = dfs(head);
        return res;
    }
   TreeNode* dfs(ListNode* head)
    {
        if (head==NULL)
            return NULL;
        int sz = 0;
        ListNode* tmp = head;
        while (tmp)
        {
            sz++;
            tmp = tmp->next;
        }
		if (sz==1)
		{
			TreeNode* curr = new TreeNode(head->val);
			return curr;
		}

        int mid = sz/2, ind=0;
        ListNode *p=head,*head2=NULL, *pmid=head, *tail0=head;
        while (p)
        {
            tail0 = p;
            p = p->next;
            if (ind==mid-1)
            {
                break;
            }
            ind++;
        }
		tail0->next = NULL;
		if (p)
			pmid = p;
		if (p)
			head2 = p->next;
        TreeNode* curr;
        if (pmid)
            curr = new TreeNode(pmid->val);
        else
            curr = NULL;
        if (curr)
        {
            curr->left = dfs(head);
            curr->right = dfs(head2); 
        }
        // else
        // {
        //     curr->left = NULL;
        //     curr->right = NULL;
        // }
        return curr;
    }
};
