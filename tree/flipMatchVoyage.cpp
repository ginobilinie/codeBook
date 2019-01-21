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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int currInd = 0;
        vector<int> myvec;
        bool flag = canMatchVoyage(root, voyage, currInd, myvec);
        if (!flag)
            return {-1};
        else
           return myvec;
    }
    //this function returns if the tree can match the current voyage (started at index currInd)
    bool canMatchVoyage(TreeNode* root, vector<int>& voyage, int &currInd, vector<int> &res)
    {
        if (!root)
            return 1;
        if (voyage[currInd]!=root->val)//not match, and we cannot fix it via swap left and right
            return 0;
        
        //if the currInd matches root, then we check the left and right one
        currInd++;
        if (root->left&&root->left->val!=voyage[currInd])
        {
            //swap left and right
            TreeNode* tmp=NULL;
            tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            res.push_back(root->val);
        }
        
        return canMatchVoyage(root->left, voyage, currInd, res)&&canMatchVoyage(root->right, voyage, currInd, res);
    }
};
