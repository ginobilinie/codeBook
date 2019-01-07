class Solution {
public:
    // vector<bool> used;
    vector<int> vec;
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        
        if (n<k||k==0)
        {
            // res.push_back(vec);
            return res;
        }
        for (int i=0; i<n; i++)
            used.push_back(0);
        for (int i=0; i<n; i++)
        {
            vec.push_back(i+1);
            dfs(n,k, i+1);
            vec.clear();
        }
        return res;
    }
    
    void dfs(int n, int k, int currInd)
    {
        if (vec.size()==k)
        {
            res.push_back(vec);
        }
        for (int i= currInd; i<n; i++)
        {
            vec.push_back(i+1);
            dfs(n,k, i+1);
            vec.pop_back();
        }
    }
};
