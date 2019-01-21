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
    bool isCompleteTree(TreeNode* root) {
         if (!root)
             return 1;
        queue<TreeNode*> myq;
        myq.push(root);
        bool res = 1;
        bool flag = 0;// the first non-complete node appears
        while(!myq.empty())
        {
            int qsz = myq.size();
            for (int i=0; i<qsz; i++)
            {
                TreeNode *curr = myq.front();
                myq.pop();
                if (flag)
                {
                    if (curr->left||curr->right)
                    {
                        res = 0;
                        break;
                    }
                }
                if (curr->left&&curr->right)
                {
                    myq.push(curr->left);
                    myq.push(curr->right);
                }
                else
                {
                    flag = 1; //the first non-complete node appears
                    if (curr->left)
                        myq.push(curr->left);
                    if (curr->right)
                    {
                        res = 0;
                        break;
                    }
                }
            }
            if (!res)
                break;
        }
        return res;
    }
};
