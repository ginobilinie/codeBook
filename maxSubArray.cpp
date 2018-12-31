class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        if (nums.empty())
            return NULL;
        dp = nums;
        int sz = nums.size();
        int maxVal = dp[0];
        //actually, we can use one currMax to replace the dp vector
        for (int i=1; i<sz; i++)
        {
            if (dp[i-1]>0)
                dp[i] = dp[i-1]+nums[i];
            if (dp[i]>maxVal)
                maxVal = dp[i];
        }
        return maxVal;
    }
};
