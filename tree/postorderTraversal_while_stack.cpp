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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> s;
        unordered_map<TreeNode*, bool> mymap;
        /*we use stack to help following the rule:
         when we go to the current node
        1. we first check if it is leaf node, if it is, we visit it and record this visit
        2. if it is not a leaf node, then we check if the left child has been visited or not, if not, store the current node, and go to the left; if visited, go to the right if right hasn't been visited, if right has been visited or null, then we directly visit the curre node, and pop the stack, and then get the top to the new pointer.
        3. if it doesn't have a left child, then we check the right child. if right one is visited, then we directly visit the current node, and pop, and then get the top as the new pointer. if right hasn't been visited, we store the current node to the stack and go to the right.
        */
        TreeNode *p = root;
        while (p)
        {
            if (p->left)
            {
                if (mymap.count(p->left))
                {
                    if (p->right)
                    {
                        if (mymap.count(p->right))
                        {
                            //directly visit p
                            vec.push_back(p->val);
                            mymap[p] = 1;
                            s.pop();
                            if (s.empty())
                            {
                                break;
                            }
                            else
                            {
                                p = s.top();
                            }
                        }
                        else
                            p = p->right;
                    }
                    else
                    {
                        //directly visit p
                        vec.push_back(p->val);
                        mymap[p] = 1;
                        s.pop();
                        if (s.empty())
                        {
                            break;
                        }
                        else
                        {
                            p = s.top();
                        } 
                    }
                }
                else
                {
                    s.push(p);
                    p = p->left;   
                }
            } 
            else if (p->right)
            {
                if (mymap.count(p->right))
                {
                    //visit itself
                    vec.push_back(p->val);
                    mymap[p] = 1;
                    s.pop();
                    if (!s.empty())
                        p = s.top();
                    else
                        break;
                }
                else
                {
                    s.push(p);
                    p = p->right;     
                }               
            }
            else //p is the leaf
            {
                vec.push_back(p->val);
                mymap[p] = 1;
                if (!s.empty())
                    p = s.top();
                else
                    break;
            }
        }
        
        
        return vec;
    }
    
    
};
