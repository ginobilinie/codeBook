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
    TreeNode *head=NULL,*prev=NULL;
    void flatten(TreeNode* root) {
       if (!root)
           return;
        if (!head)
            head = root;
        TreeNode* tmp = root, *leftnode, *rightnode;
        if (!prev)
        {
             prev = root;
            leftnode = root->left;
            rightnode = root->right;
        }
        else
        {
            tmp = prev;
            leftnode = root->left;
            rightnode = root->right;
            prev->right = root;
            prev->left = NULL;  
            prev = root;
        }
        flatten(leftnode);
        flatten(rightnode);    
        //root = head;
        //prev = tmp;
    }
};
