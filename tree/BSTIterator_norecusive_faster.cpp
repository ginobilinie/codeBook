/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        currNode = root;
        inorder(root);
        currInd = 0;
    }
    
    /** @return the next smallest number */
    int next() {
        if (hasNext()==0)
            return -1;
        return myvec[currInd++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
       if (currInd<myvec.size())
            return true;
        else
            return false;
    }
    void inorder(TreeNode* root)
    {
        // if (!root)
        //     return;
        // inorder(root->left);
        // myvec.push_back(root->val);
        // inorder(root->right);
        if (!root)
            return;
        stack<TreeNode*> s;
        //s.push(root);
        TreeNode *currNode=root;
        //unordered_set<TreeNode*> myset;
        int ind = 0;
        while (currNode||!s.empty())
        {
            while (currNode)
            {
                s.push(currNode);
                currNode = currNode->left;
            }
            //now currNode should be NULL
            currNode = s.top();
            s.pop();
            myvec.push_back(currNode->val);
            currNode = currNode->right;
        }
    }
private:
    TreeNode* currNode;
    vector<int> myvec;
    int currInd;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
