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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> myq;
        queue<int> levelq;
        myq.push(root);
        levelq.push(0);
        vector<int> vec;
        vector<vector<int>> res;
        while(!myq.empty())
        {
            TreeNode* curr = myq.front();
            myq.pop();
            int level = levelq.front();
            levelq.pop();
            vec.push_back(curr->val);
            if (levelq.empty()||level!=levelq.front())
            {
                res.push_back(vec);
                vec.clear();
            }
            if (curr->left)
            {
                myq.push(curr->left);
                levelq.push(level+1);
            }
            if (curr->right)
            {
                myq.push(curr->right);
                levelq.push(level+1);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
