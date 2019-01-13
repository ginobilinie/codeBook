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
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        preorder(root, 0);
        return sum;
    }
    
    void preorder(TreeNode* root, int currSum)
    {
        int tmp = currSum;
        currSum = currSum*10 + root->val;
        if (!root->left&&!root->right)
        {
            sum += currSum;
            return;
        }
        if (root->left)
            preorder(root->left, currSum);
        if (root->right)
            preorder(root->right, currSum);
        currSum = tmp;
    }
};
