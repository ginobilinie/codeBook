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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> s;
        
        while (root)
        {
            vec.push_back(root->val);
            if (root->right)
                s.push(root->right);
            root = root->left;
            if (!root&&!s.empty())
            {
                root = s.top();
                s.pop();
            }
        }
        return vec;
    }
    

};
