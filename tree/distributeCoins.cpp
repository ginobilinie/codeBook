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
    int distributeCoins(TreeNode* root) {
        if (!root)
            return 0;
        int res = dfs(root);
        return res;
    }
    //we clean the tree down side to up side, and left side to right side.
    //actually, it is a postorder traverse
    int dfs(TreeNode* root)
    {
        if (!root)
            return 0;
        int cnt = 0;
        if (root->left)
        {
            cnt += dfs(root->left);
            if (root->left->val!=1)
            {
                cnt += abs(root->left->val- 1);
                root->val += root->left->val-1;
            }
        }
        if (root->right)
        {
            cnt += dfs(root->right);
            if (root->right->val!=1)
            {
                cnt += abs(root->right->val - 1);
                root->val += root->right->val - 1;
            }
        }
        return cnt;
    }
};
