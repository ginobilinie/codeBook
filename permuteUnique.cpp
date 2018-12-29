class Solution {
public:
 
    set<vector<int>> myset;
    vector<bool> used;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> currNums;
        vector<vector<int>> rr;
        if (nums.empty())
        {
            // rr.push_back(currNums);
            return rr;
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
        vector<vector<int>> res(myset.begin(),myset.end());
        return res;
    }
    
    //k indicates the current size for currNums
    void dfs(vector<int>& nums, vector<int>& currNums)
    {
        if (currNums.size()==nums.size())
        {
            myset.insert(currNums);
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
