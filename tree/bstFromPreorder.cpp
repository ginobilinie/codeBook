/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
 Return the root node of a binary search tree that matches the given preorder traversal.
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        //we insert one element at each time
        for (int i=1; i<preorder.size(); i++)
            dfs(root, preorder[i]);
        return root;
    }
    void dfs(TreeNode* root, int val)
    {
        if (val<root->val)//go to left
        {
            if (!root->left)
            {
                TreeNode* node = new TreeNode(val);
                root->left = node;                
            }
            else 
                dfs(root->left,val);
        }
        else
        {
            if (!root->right)
            {
                TreeNode* node = new TreeNode(val);
                root->right = node;                      
            }
            else
                dfs(root->right, val);
        }
           
    }
};
