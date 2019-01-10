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
    vector<int> nums;
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        if (nums.size()==1)
            return true;
        
        dfs(root);
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i-1]>=nums[i])
            {
                return false;
                break;
            }
        }
        return true;
    }
    
    void dfs(TreeNode* root)
    {
        if (!root)
            return;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
};
