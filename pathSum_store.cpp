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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return {};
        vector<int> vec;
        dfs(root,vec,0,sum);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int>& currVec, int currSum, int sum)
    {
        if (!root) return;
        currVec.push_back(root->val);
        if (!root->left&&!root->right&&currSum+root->val==sum)
        {
            res.push_back(currVec);
        }
        dfs(root->left,currVec,currSum+root->val,sum);
        dfs(root->right,currVec,currSum+root->val,sum);
        currVec.pop_back();
    }
};
