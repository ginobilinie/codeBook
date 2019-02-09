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
    struct node
    {
        int x;
        int y;
        int val;
        node(int a, int b, int c):x(a),y(b),val(c)
        {
            
        }
    };
    struct cmp
    {
        bool operator() (const node& n1, const node& n2) const
        {
            if (n1.x==n2.x&&n1.y==n2.y) return n1.val<n2.val;
            if (n1.x==n2.x) return n1.y>n2.y;
            return n1.x<n2.x;
        }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root)
            return {};
        // map<struct node, int, cmp> mymap;
        set<struct node, cmp> myset;
        node mynode(0,0,root->val);
        dfs(root,mynode,myset);
        
        // cout<<mymap.size()<<endl;
        int x = INT_MAX;
        vector<vector<int>> res;
        vector<int> tvec;
        for (auto it : myset)
        {
            auto loc = it;
            int val = loc.val;
            // cout<<loc.x<<","<<loc.y<<":"<<val<<endl;
            if (x==INT_MAX)
            {
                x = loc.x;
                tvec.push_back(val);
            }
            else
            {
                if (x==loc.x)
                {
                    tvec.push_back(val);
                }
                else
                {
                    res.push_back(tvec);
                    tvec.clear();
                    x = loc.x;
                    tvec.push_back(val);
                }
            }
        }
        if (!tvec.empty())
            res.push_back(tvec);
        return res;
    }
    
    void dfs(TreeNode* root, node& mynode, set<node, cmp>& myset)
    {
        if (!root)
            return;
        myset.insert(mynode);
        if (root->left)
        {
            node lnode(mynode.x-1,mynode.y-1, root->left->val);
            dfs(root->left, lnode, myset);            
        }
        if (root->right)
        {
            node rnode(mynode.x+1, mynode.y-1, root->right->val);
            dfs(root->right, rnode, myset);            
        }
    }
};
