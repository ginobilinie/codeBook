class Solution {
public:
    int brokenCalc(int X, int Y) {
        int maxV = max(X,Y);
        vector<int> dp(maxV+1,0);
        dp[X] = 0;
        for (int i=X-1; i>0; i--)
        {
            if (i%2)
            {
                dp[i] = min(dp[i+1]+1,dp[(i+1)/2]+2);
            }
            else
            {
                dp[i] = min(dp[i+1],dp[i/2])+1;
            }
        }
        
        for (int i=X+1; i<maxV+1; i++)
        {
            if (i%2)
            {
                dp[i] = min(dp[i+1]+1,dp[(i+1)/2]+2);
            }
            else
            {
                dp[i] = min(dp[i+1],dp[i/2])+1;
            }
        }
        return dp[Y];
    }
};
