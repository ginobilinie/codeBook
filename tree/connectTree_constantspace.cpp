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
        //two observations (we assue a perfect binary tree)
        //ob1. root->left->next = root->right;
        //ob2. root->right->ext = root->next->left;
        
        //for head node
        root->next = NULL;
        TreeLinkNode* leftmost;
        leftmost = root;
        while (root)
        {
            if (root->left)
                root->left->next = root->right;
            if (root->right)
                if (root->next)
                    root->right->next = root->next->left;
                else
                    root->right->next = NULL;
            if (root->next)
                root = root->next;
            else
            {
                root = leftmost->left;
                leftmost = root;
            }
        }
        return;
    }
};
