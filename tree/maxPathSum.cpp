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
    #define maxVal(x,y) x<y?y:x
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        int res = INT_MIN; //res is the result with cross branch search
        dfs(root, res);
        return res;  
    }
    
    //we return the single branch maxmum sum of a certain path
    //res is the current mainint maxum path sum with considering cross branch path
    int dfs(TreeNode* root, int& res)
    {
        if (!root)
            return 0;
        int left = dfs(root->left,res);//max value in the left branch
        int right = dfs(root->right,res);//max value in the right branch
        int max_single_branch = maxVal(left,right);
        max_single_branch = maxVal(0, max_single_branch);
        max_single_branch +=root->val;
        int max_total = maxVal(max_single_branch, left+right+root->val);
        res = maxVal(res,max_total);
        return max_single_branch; 
    }
    
};
