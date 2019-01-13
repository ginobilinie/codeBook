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
        TreeLinkNode* leftmost = root;
        while (root)
        {
            if (root->left)
            {
                if (root->right)
                    root->left->next = root->right;
                else
                {
                    TreeLinkNode* tmp = root;
                    while (tmp->next&&!tmp->next->left&&!tmp->next->right)
                        tmp = tmp->next;
                    if (root==tmp)//rightmost one
                    {
                        root->left->next = NULL;//go to next layer
                        while(leftmost&&!leftmost->left&&!leftmost->right)
                            leftmost = leftmost->next;
                        if (!leftmost)
                            return;
                        else if (leftmost->left)
                            root = leftmost->left;
                        else if (leftmost->right)
                            root = leftmost->right;
                        else
                            return;
                    }
                    else
                    {
                        if (tmp->left)
                            root->left->next = tmp->left;
                        else if (tmp->right)
                            root->left->next = tmp->right;
                        else
                            root->left->next = NULL;
                        root = tmp;
                    }
                }
            }
            if (root->right)
            {
                TreeLinkNode* tmp = root;
                while (tmp->next&&!tmp->next->left&&!tmp->next->right)
                    tmp = tmp->next;
                if (root==tmp)//rightmost one
                {
                    root->right->next = NULL;//go to next layer
                    while(leftmost&&!leftmost->left&&!leftmost->right)
                        leftmost = leftmost->next;
                    if (!leftmost)
                        return;
                    else if (leftmost->left)
                        root = leftmost->left;
                    else if (leftmost->right)
                        root = leftmost->right;
                    else
                        return;
                }
                else
                {
                    if (tmp->left)
                        root->right->next = tmp->left;
                    else if (tmp->right)
                        root->right->next = tmp->right;
                    else
                        root->right->next = NULL;
                    root = tmp;
                    // if (root)
                }
            }
        }
    }
};
