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
        int res = 0;
        postorder(root, root, res);
        return res;
    }
    //we clean the tree down side to up side, and left side to right side.
    //actually, it is a postorder traverse
    void postorder(TreeNode* parent, TreeNode* child, int &res)
    {
        if (!child)
            return ;
        postorder(child, child->left, res);
        postorder(child, child->right, res);
        //if child node is well done, we donot need to do anything
        if (child->val==1)
            return;
        //otherwise, we should transfer child->val - 1 to satisfy it
        res += abs(child->val - 1);
        parent->val += child->val - 1;
    }
};
