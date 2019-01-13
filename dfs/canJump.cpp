class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return true;
        int sz = nums.size();
        bool res = dfs(nums, 0);
        return res;
    }
    
    bool dfs(vector<int>& nums, int currInd)
    {
        if (currInd==nums.size()-1)
        {
            return true;
        }
        bool res = false;
        int possibleSteps = nums[currInd];
        int needSteps = nums.size()-1 - currInd;
        if (possibleSteps>=needSteps)
            return true;
        else
        {
            for (int i=1; i<=possibleSteps; i++)
            {
                res = res || dfs(nums, currInd+i);
                if (res)
                    return res;
            } 
            return res;
        }
        //return res;
    }
};
