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
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return {};
        vector<TreeNode*> res;
        dfs(1,n,res);
        return res;
    }
    
    void dfs(int l, int r, vector<TreeNode*> & treeVec)
    {
        // vector<TreeNode*> *treeVec = new vector<TreeNode*>();
  
        if (l>r)
        {
            treeVec.push_back(NULL);
            // return treeVec;
            return;
        }
        for (int i=l; i<=r; i++)//use i as the seperator
        {
            vector<TreeNode*> leftTreeVec;
            dfs(l,i-1, leftTreeVec);
            vector<TreeNode*> rightTreeVec;
            dfs(i+1,r, rightTreeVec);
            for (int k=0; k<leftTreeVec.size(); k++)
            {
                TreeNode* leftTree = leftTreeVec[k];
                for (int t=0; t<rightTreeVec.size(); t++)
                {
                    TreeNode* rightTree = rightTreeVec[t];
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    treeVec.push_back(root);
                }
            }
        }
        //return treeVec;
        return;
    }
    
};
