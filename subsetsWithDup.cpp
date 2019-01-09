class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        int i;
        for (i=0; i<nums.size(); i++)
        {
            tmp.push_back(nums[i]);
            dfs(nums, tmp, i);
            tmp.clear();
            while(i+1<nums.size()&&nums[i]==nums[i+1])
                i++;
        }
        res.push_back(tmp);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int> vec, int currInd)
    {
        if(vec.size()>nums.size())
            return;
        res.push_back(vec);
        vector<int> tmp;
        for (int i=currInd+1; i<nums.size(); i++)
        {
            vec.push_back(nums[i]);
            dfs(nums, vec, i);
            vec.pop_back();
            while(i+1<nums.size()&&nums[i]==nums[i+1])
                i++;
        }
    }
};
