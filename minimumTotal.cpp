class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty())
            return 0;
        vector<vector<int>> dp = triangle;
        int minVal = INT_MAX;
        
        for (int i=1; i<triangle.size(); i++)
        {
            vector<int> line = triangle[i];
            dp[i][0] = dp[i-1][0]+dp[i][0];
            dp[i][line.size()-1] = dp[i-1][line.size()-2] + dp[i][line.size()-1];
            for (int j=1; j<line.size()-1; j++)
            {
                dp[i][j] = dp[i][j] + (dp[i-1][j]<dp[i-1][j-1]?dp[i-1][j]:dp[i-1][j-1]);
            }
        }
        vector<int> linex = dp[dp.size()-1];
        for (int i=0; i<linex.size(); i++)
        {
            if (linex[i]<minVal)
                minVal = linex[i];
        }
        return minVal;
    }
};
