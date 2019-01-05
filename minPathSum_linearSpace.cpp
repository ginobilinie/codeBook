class Solution {
public:
    #define min(x,y) x<y?x:y
    int minPathSum(vector<vector<int>>& grid) {
        //using one-dim dp with linear space complexity
        //but with O(mn) time complexity.
        //dp[i] means the min path sum for the ith column of the current's row.
        if (grid.empty())
            return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> dp(cols,0);
        dp[0] = grid[0][0];
        for (int i=1; i<cols; i++)
            dp[i] = dp[i-1] + grid[0][i];
        
        for (int i=1; i<rows; i++)
        {
            dp[0] = dp[0] + grid[i][0];
            for (int j=1; j<cols; j++)
            {
                dp[j] = grid[i][j] + (dp[j-1]<dp[j]?dp[j-1]:dp[j]); // actually dp[j-1] is dp[i][j-1], and dp[j] is dp[i-1][j]
            }
        }
        return dp[cols-1];
    }
};
