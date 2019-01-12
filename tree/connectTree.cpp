/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> myq;
        queue<int> levelq;
        myq.push(root);
        levelq.push(0);
        while (!myq.empty())
        {
            TreeLinkNode *node = myq.front();
            myq.pop();
            int level = levelq.front();
            levelq.pop();
            if (levelq.empty()||level!=levelq.front())
            {
                node->next = NULL;
            }
            else
            {
                node->next = myq.front();
            }
            if (node->left)
            {
                myq.push(node->left);
                levelq.push(level+1);
            }
            if (node->right)
            {
                myq.push(node->right);
                levelq.push(level+1);
            }
        }
    }
};
