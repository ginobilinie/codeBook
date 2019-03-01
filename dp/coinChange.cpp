class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount==0)
            return 0;
        if (amount<0)
            return -1;
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for (int i=1; i<amount+1; i++)
        {
            for (int coin:coins)
            {
                if (i-coin>=0)
                    dp[i] = min(dp[i-coin],dp[i]);
            }
            if (dp[i]!=INT_MAX)
                dp[i]++;
        }
        if (dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
};
