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
    vector<int> postorderTraversal(TreeNode* root) {
        /*
        I also write another non-recursive version using two stacks
        The first stack stores the current node's left and right child nodes, and pop the top one to the sencond stack,
        which means the 2nd stack acutally stores the reverse order of the post-oreder traverse
        */
        if (!root)
           return {};
        vector<int> vec;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        TreeNode* currNode;
        while (!s1.empty())
        {
            currNode = s1.top();
            s1.pop();
            s2.push(currNode);
            if (currNode->left)
                s1.push(currNode->left);
            if (currNode->right)
                s1.push(currNode->right);
        }
        
        while(!s2.empty())
        {
            currNode = s2.top();
            s2.pop();
            vec.push_back(currNode->val);
        }
        return vec;
    }
    
    
};
