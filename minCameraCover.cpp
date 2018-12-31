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
    //define some statuses
    const int NO_CAMERA_COVERED = 1 // this is no camera to cover the current node
    const int HAS_CAMERA_COVERED = 2 // we have already got some camera to cover the current node
    const int NO_CAMERA_NEEDED = 3 //we donot need a camera to cover the current node (for example, null), note to distinguish betwen 2 and 3
    int res = 0;
    int minCameraCover(TreeNode* root) {
        int status = dfs(root);
        if (status==1)
            res++;
        return res;
    }
    
    /*greedy algorithm + dfs:
        1. if left or right child nodes of the current node has no camera covered (1), then we must set a camera for the current node, we return has camera covered
        2. if the left or right child nodes of the current node has (at least one) camera covered, we donot need a camera for the current node, we return no camera needed
        3. else, we return there is no camera covered
    */
    int dfs(TreeNode* root)
    {
        if (!root)
            return NO_CAMERA_NEEDED;
        int left = dfs(root->left);
        int right =dfs(root->right);
        
        if (left==NO_CAMERA_COVERED||right==NO_CAMERA_COVERED)
        {
            res++;
            return HAS_CAMERA_COVERED;
        } 
        else if (left==HAS_CAMERA_COVERED||right==HAS_CAMERA_COVERED)
        {
            return NO_CAMERA_NEEDED;
        }
        else //which means left and right are both 3(no camera needed), as we are preorder traverse, which means the current node is not coverted yet
        {
            return NO_CAMERA_COVERED;
        }
    }
};
