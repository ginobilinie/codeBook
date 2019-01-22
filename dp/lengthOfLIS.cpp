class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int sz = nums.size();
        vector dp(sz, 1);
        for (int i=0; i<sz; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (nums[i]>nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        int maxLen = 1;
        for (int i=0; i<sz; i++)
        {
            if (dp[i]>maxLen)
                maxLen = dp[i];
        }
        return maxLen;
    }
};
