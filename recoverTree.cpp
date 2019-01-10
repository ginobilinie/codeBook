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
    int ind = 0;
    void recoverTree(TreeNode* root) {
        if (!root)
            return;
        dfs(root);
        sort(nums.begin(),nums.end());
        adjustTree(root);
    }
    
    void dfs(TreeNode* root)
    {
        if (root==NULL)
            return;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
    
    //adjust the tree without changing the structure.
    void adjustTree(TreeNode *root)
    {
        if (root==NULL)
            return;
        adjustTree(root->left);
        if (ind<nums.size())
            root->val = nums[ind++];
        adjustTree(root->right);
    }
};
