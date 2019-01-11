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
    #define minVal(x,y) x<y?x:y
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int ld = minDepth(root->left);
        int rd = minDepth(root->right);
        int d = minVal(ld,rd);
        if (ld==0)
            d = rd;
        if (rd==0)
            d = ld;
        d = d+1;
        return d;
    }
};
