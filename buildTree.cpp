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
    // TreeNode* root;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0)
            return NULL;
        if (preorder.size()!=inorder.size())
            return NULL;
        
        int head = preorder[0];
        TreeNode* currNode = new TreeNode(head);
        //partition inorder to two half
        // vector<int> leftvec_inorder, rightvec_inorder;
        int ind = -1;
        for (int i=0; i<inorder.size(); i++)
        {
            if (inorder[i]==head)
            {
                ind = i;
                break;
            }
        }
        if (ind!=0)
        {
            vector<int> leftvec_inorder(inorder.begin(),inorder.begin()+ind);
            vector<int> leftvec_preorder(preorder.begin()+1,preorder.begin()+1+ind);
            currNode->left = buildTree(leftvec_preorder,leftvec_inorder);
        }
        else
        {
            currNode->left = NULL;
        }
        
        if (ind!=inorder.size()-1)
        {
            vector<int> rightvec_inorder(inorder.begin()+ind+1, inorder.end());
            vector<int> rightvec_preorder(preorder.begin()+ind+1, preorder.end());  
            currNode->right = buildTree(rightvec_preorder,rightvec_inorder);
        }
        else
        {
            currNode->right = NULL;
        }

        return currNode;
    }
};
