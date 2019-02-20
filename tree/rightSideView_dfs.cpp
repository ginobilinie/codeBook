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
    vector<int> rightSideView(TreeNode* root) {
        //first solution, use bfs
        int level = 0;
        vector<int> res;
        dfs(root, level, res);
        return res;
    }
    void dfs(TreeNode* root, int level, vector<int>& res)
    {
        if (!root)
            return;
        if (level>=res.size())
            res.push_back(root->val);
        else//overwrite if it is not the rightmost one on a level
            res[level] = root->val;
        dfs(root->left,level+1,res);
        dfs(root->right,level+1,res);
    }
};
