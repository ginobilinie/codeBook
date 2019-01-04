class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty())
            return 0;
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        
        int dp[100][100];

        for (int i=0; i<rows; i++)
            if (obstacleGrid[i][0])
            {
                dp[i][0] = 0;    
                for (int k=i+1; k<rows; k++)
                    dp[k][0] = 0;
                break;
            }
            else
                dp[i][0] = 1;
        for (int j=0; j<cols; j++)
            if (obstacleGrid[0][j])
            {
                dp[0][j] = 0;
                for (int k=j+1; k<cols; k++)
                    dp[0][k] = 0;
                break;                
            }
            else
                dp[0][j] = 1;
        
        for (int i=1; i<rows; i++)
            for (int j=1; j<cols; j++)
            {
                if (obstacleGrid[i][j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        int res = dp[rows-1][cols-1];
        return res;
    }
};
