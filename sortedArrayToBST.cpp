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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        int sz = nums.size();
        TreeNode *res = dfs(nums, 0, sz-1);
        return res;
    }
    
    TreeNode* dfs(vector<int>& nums, int l, int r)
    {
        if (l>r)
            return NULL;
        int mid = (l+r)/2;
        int head = nums[mid];
        TreeNode *curr = new TreeNode(head);
        curr->left = dfs(nums,l,mid-1);
        curr->right = dfs(nums,mid+1,r);
        return curr;
    }
};
