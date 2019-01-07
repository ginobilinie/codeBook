class Solution {
public:
    vector<vector<int>> res;
    vector<int> currVec;
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty())
            return res;

        for (int i=0; i<nums.size(); i++)
        {
            currVec.push_back(nums[i]);
            dfs(nums, i);
            currVec.clear();
        }
        vector<int> tmp;
        res.push_back(tmp);
        return res;
    }
    
    void dfs(vector<int>& nums, int currInd)
    {
        res.push_back(currVec);

        for (int i=currInd+1; i<nums.size(); i++)
        {
            currVec.push_back(nums[i]);
            dfs(nums, i);
            currVec.pop_back();
        }
    }
};
