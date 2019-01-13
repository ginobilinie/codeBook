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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size()==0)
            return NULL;
        if (postorder.size()!=inorder.size())
            return NULL;
        int sz = postorder.size();
        int head = postorder[sz-1];
        TreeNode* currNode = new TreeNode(head);
        int ind = -1;
        for (int i=0; i<sz; i++)
        {
            if (inorder[i]==head)
            {
                ind = i;
                break;
            }
        }
        //partition
        if (ind!=0)
        {
            vector<int> left_inorder(inorder.begin(),inorder.begin()+ind);
            vector<int> left_postorder(postorder.begin(),postorder.begin()+ind);
            currNode->left = buildTree(left_inorder,left_postorder);
        }
        else
        {
            currNode->left = NULL;
        }
        if (ind!=sz-1)
        {
            vector<int> right_inorder(inorder.begin()+ind+1,inorder.end());
            vector<int> right_postorder(postorder.begin()+ind,postorder.end()-1);
            currNode->right = buildTree(right_inorder,right_postorder);
        }   
        else
        {
            currNode->right = NULL;
        }
        return currNode;
    }
};
