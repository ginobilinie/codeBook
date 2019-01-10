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
    TreeNode* bigger = NULL;
    TreeNode* smaller = NULL;
    TreeNode* prev = NULL;
    //actually, this is not a very general method, and it can only be used for this problem
    //since it can only solve two element's switch mistake
    void recoverTree(TreeNode* root) {
        adjustTree(root);
        if (bigger && smaller)  {
            int tmp = bigger->val;
            bigger->val = smaller->val;
            smaller->val = tmp;
        }
    }
    
    
    //adjust the tree without changing the structure using in-order traverse
    void adjustTree(TreeNode *root)
    {
        if (!root)
            return;
        
        adjustTree(root->left);
        
        //since we are using in-order traverse, thhus, prev->val(previously visited node) should be smaller 
        //than the current node (root), if it is bigger, then we should 
        if (prev && prev->val > root->val)   
        {
            if (!bigger) {
                bigger = prev;
                smaller = root;
            }
            else
                smaller = root;
        }
        prev = root;
        
        adjustTree(root->right);
    }
};
