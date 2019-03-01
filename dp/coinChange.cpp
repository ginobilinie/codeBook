class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount==0)
            return 0;
        vector<int> dp(amount+1,0);
        
        for (int i=1; i<amount+1; i++)
        {
            for (int coin:coins)
            {
                if (i-coin>0)
                    dp[i] = min(dp[i-coin],dp[i])+1;
            }
        }
        if (dp[amount]==0)
            return -1;
        return dp[amount];
    }
};
