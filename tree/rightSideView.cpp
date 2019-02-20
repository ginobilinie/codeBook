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
    vector<int> rightSideView(TreeNode* root) {
       //first solution, use bfs
        if (!root)
            return {};
        vector<int> res;
        queue<TreeNode*> myq;
        myq.push(root);
        while (!myq.empty())
        {
            int sz = myq.size();
            for (int i=0; i<sz-1; i++)
            {
                TreeNode* tn = myq.front();
                myq.pop();
                if (tn->left)
                    myq.push(tn->left);
                if (tn->right)
                    myq.push(tn->right);
            }
            TreeNode* tn = myq.front();
            myq.pop();
            res.push_back(tn->val);
            if (tn->left)
                myq.push(tn->left);
            if (tn->right)
                myq.push(tn->right);
        }
        return res;
    }
    
 
};
