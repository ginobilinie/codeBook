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
    //observation
    //ob1. if (root->right) root->left->next = root->right, else root->left->next = root->next->left (or right), we can use while to check the first found one
    //ob2. root->right->next = root->next->left (or right), we can use while to check the first found one.
    void connect(TreeLinkNode *root) {
        if (!root) return;
        root->next = NULL;
        while (root)
        {
            if (root->left)
            {
                if (root->right)
                    root->left->next = root->right;
                else
                {
                    while (root->next&&!root->)
                }
            }
        }
    }
};
