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
    TreeNode* firstViolatedNode = NULL;
    TreeNode* lastViolatedNode = NULL;
    TreeNode* prev = NULL;
    //actually, this is not a very general method, and it can only be used for this problem
    //since it can only solve two element's switch mistake
    void recoverTree(TreeNode* root) {
        adjustTree(root);
        if (firstViolatedNode && lastViolatedNode)  {
            int tmp = firstViolatedNode->val;
            firstViolatedNode->val = lastViolatedNode->val;
            lastViolatedNode->val = tmp;
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
            if (!firstViolatedNode) {
                firstViolatedNode = prev;
                lastViolatedNode = root;
            }
            else
                //since there are only two elements wrongly swapped, so we should remember the first
                //out of order value (should be bigger) and the last out of order value (should be smaller)
                //but this algorithm only suits for there are only two wrongly swapped nodes.
                lastViolatedNode = root; 
        }
        prev = root;
        
        adjustTree(root->right);
    }
};
