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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        bool res = isSymmetricTrees(root->left, root->right);
        return res;
        
    }
    
    bool isSymmetricTrees(TreeNode* leftTree, TreeNode* rightTree)
    {
        if (!leftTree&&!rightTree)
            return true;
        if ((!leftTree&&rightTree)||(leftTree&&!rightTree))
            return false;
        if (leftTree->val!=rightTree->val)
            return false;
        bool flag1 = isSymmetricTrees(leftTree->left,rightTree->right);
        if (!flag1)
            return false;
        bool flag2 = isSymmetricTrees(leftTree->right,rightTree->left);
        if (!flag1||!flag2)
            return false;
        return true;
    }
};
