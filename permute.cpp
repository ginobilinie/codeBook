class Solution {
public:
    vector<vector<int>> res;
    vector<bool> used;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> currNums;
        if (nums.empty())
        {
            res.push_back(currNums);
            return res;
        }
        for (int i=0; i<nums.size(); i++)
            used.push_back(0);
        for (int i=0; i<nums.size(); i++)
        {
            currNums.push_back(nums[i]);
            used[i] = 1;
            dfs(nums,currNums);
            currNums.clear();
            used[i] = 0;
        }
        return res;
    }
    
    //k indicates the current size for currNums
    void dfs(vector<int>& nums, vector<int>& currNums)
    {
        if (currNums.size()==nums.size())
        {
            res.push_back(currNums);
            return;
        }
        vector<int> tmp;
        for (int i=0; i<nums.size(); i++)
        {
            if (!used[i])
            {
                used[i] = 1;
                tmp = currNums;
                currNums.push_back(nums[i]);
                dfs(nums, currNums);
                used[i] = 0;
                currNums = tmp;
                // currNums.erase(currNums.end());
            }
        }
    }
};
