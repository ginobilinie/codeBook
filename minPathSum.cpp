class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp = grid;
        for (int i=1; i<rows; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for (int j=1; j<cols; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];
        for (int i=1; i<rows; i++)
            for (int j=1; j<cols; j++)
            {
                dp[i][j] = grid[i][j] + (dp[i-1][j]>dp[i][j-1]?dp[i][j-1]:dp[i-1][j]);
            }
        return dp[rows-1][cols-1];
    }
};
