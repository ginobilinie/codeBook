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
    #define maxVal(x,y) x<y?y:x
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        int d = max(ld,rd);
        d = d+1;
        return d;
    }
};
