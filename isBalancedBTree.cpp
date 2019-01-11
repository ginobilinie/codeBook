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
    bool flag = 1;
    bool isBalanced(TreeNode* root) {
        // bool res = 1;
        dfs(root);
        return flag;
    }
    
    int dfs(TreeNode* root)
    {
        if (!root)
        {
            //flag = 1;
            return 0;
        }
        int depth = 0;
        if (flag)
        {
            int leftDepth = dfs(root->left);
            int rightDepth = dfs(root->right);
            if (abs(leftDepth-rightDepth)>1)
            {
                flag = false;
            }
            depth = leftDepth>rightDepth?leftDepth:rightDepth;
            depth = depth + 1;
        }
        return depth;     
    }
};
