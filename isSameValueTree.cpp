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
    bool isSameValueTree(TreeNode* root, int val)
    {
        if (root==NULL)
            return true;
        if (root->val!=val)
            return false;
        return isSameValueTree(root->left,val)&&isSameValueTree(root->right,val);
    }
    bool isUnivalTree(TreeNode* root) {
        if (root==NULL)
            return true;
        int val = root->val;
        bool res = isSameValueTree(root,val);
        return res;
    }
};
