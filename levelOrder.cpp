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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> myqueue;
        queue<int> levelqueue;
        myqueue.push(root);
        levelqueue.push(0);
        TreeNode* curr;
        vector<int> vec;
        while(!myqueue.empty())
        {
            curr = myqueue.front();
            myqueue.pop();
            vec.push_back(curr->val);
            int currLevel = levelqueue.front();
            levelqueue.pop();
            if (levelqueue.empty()||currLevel!=levelqueue.front())
            {
                res.push_back(vec);                
                vec.clear();
            }

            if (curr->left)
            {
                myqueue.push(curr->left);
                levelqueue.push(currLevel+1);
            }

            if (curr->right)
            {
                myqueue.push(curr->right);
                levelqueue.push(currLevel+1);
            }
        }
        return res;
    }
};
