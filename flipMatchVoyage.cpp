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
    vector<int> res;
    int ind=0;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        // vector<int> res;
        if (root==NULL&&voyage.empty())
            return res;
        if (root==NULL&&!voyage.empty()||root&&voyage.empty())
        {
            res.push_back(-1);
            return res;
        }
        
        return res;
    }
    void preorder(TreeNode* root, vector<int>& voyage)
    {
        if (root==NULL)
            return true;
        if (root->val==voyage(ind))
        {
            ind++;
            bool left = preorder(root->left, voyage);
            ind++;
            bool right = preorder(root->right, voyage);
            
            if (left&&right)
            {
                
            }
            else// adjust or check
            {
                if (root->left->val==voyage[ind] && root->right->val == voyage[ind-1])
                {
                    
                }
            }
            return true;
        }
        else
        {
            return false;
        }

    }
        
};
