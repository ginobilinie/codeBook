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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root&&!sum)
            return false;
        bool flag = 0;
        dfs(root, flag, 0, sum);
        return flag;
    }
    
    void dfs(TreeNode* root, bool& flag, int currSum, int sum)
    {
        if (flag)
            return;
        if (!root)
        {
            // if (currSum==sum)
            //     flag = 1;
            return;
        }
         
        if (!root->left&&!root->right && currSum+root->val==sum)
        {
            flag = 1;
            return;
        }
        
        dfs(root->left,flag, currSum+root->val, sum);
        dfs(root->right,flag, currSum+root->val, sum);
    }
};
