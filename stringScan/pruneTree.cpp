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
    TreeNode* pruneTree(TreeNode* root) {
        bool res = isContainOne(root);
        if (res)
            return root;
        else
            return NULL;
    }
    
    
    bool isContainOne(TreeNode* root)
    {
        // if (!root)
        //     return true;
        if (!root->left&&!root->right)
        {
            if (root->val)
                return true;
            else
            {
                // root = NULL;
                return 0;   
            }
        }
        bool left = false;
        bool right = false;
        if (root->left)
        {
            left = isContainOne(root->left);
            if (!left)
                root->left = NULL;            
        }

        if (root->right)
        {
            right = isContainOne(root->right);
            if (!right)
                root->right = NULL;
        }
        return left||right||root->val==1;
    }
};
