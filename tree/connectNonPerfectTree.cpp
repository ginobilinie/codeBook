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
    
    //the very important point is here: we implictly point the head to the first pointer of the next layer
    //since tmp directly link with head, so the first touch of tmp in a new layer, then it is assigned to head implictly.
    //tmp is used to connect pointers in a layer implictly
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        TreeLinkNode head(0), *tmp = &head;
        while (root)
        {
            if (root->left)
            {
                tmp->next = root->left;
                tmp = tmp->next;//we dont worry to point to the next node for the root->left->next at this time
            }
            if (root->right)
            {
                tmp->next = root->right;//here, we just point the left pointer to next right, great idea
                tmp = tmp->next;
            }
            if (root->next)
            {
                root = root->next;
            }
            else//right most pointer
            {
                //go to next layer
                root = head.next;
                //clear tmp and head
                head.next = NULL;
                tmp = &head;
            }
            
        }
    }
};
