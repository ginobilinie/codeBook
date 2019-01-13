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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> myqueue;
        queue<int> levelqueue;
        myqueue.push(root);
        levelqueue.push(0);
        vector<int> vec;
        vector<vector<int>> res;
        TreeNode *curr;
        int cnts = 0;
        while(!myqueue.empty())
        {
            curr = myqueue.front();
            myqueue.pop();
            int level = levelqueue.front();
            levelqueue.pop();
            vec.push_back(curr->val);
            if (levelqueue.empty()||level!=levelqueue.front())
            {
                cnts++;
                if (cnts%2==1)
                    res.push_back(vec);
                else
                {
                    reverse(vec.begin(),vec.end());
                    res.push_back(vec);
                }
                vec.clear();
            }
            if (curr->left)
            {
                myqueue.push(curr->left);
                levelqueue.push(level+1);
            }
            if (curr->right)
            {
                myqueue.push(curr->right);
                levelqueue.push(level+1);
            }
        }
        return res;
    }
};
