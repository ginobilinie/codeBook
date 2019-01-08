class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        int maxVal = 0;
        
        if (matrix[0][0]=='1')
            dp[0][0] = 1;
        maxVal = dp[0][0];
        for (int i=1; i<cols; i++)
        {
            if (matrix[0][i]=='1')
            {
                dp[0][i] = dp[0][i-1]+1;
                if (maxVal<dp[0][i])
                    maxVal = dp[0][i];
            }
        }
        for (int i=1; i<rows; i++)
        {
            if (matrix[i][0]=='1')
            {
                dp[i][0] = dp[i-1][0]+1;
                if (maxVal<dp[i][0])
                    maxVal = dp[i][0];
            }
        }
        int prevRow,numOfCols,a;
        for (int i=1; i<rows; i++)
        {
            if (matrix[i][0]=='1')
                dp[i][0] = 1;
            for (int j=1; j<cols; j++)
            {
                if (matrix[i][j]=='1')
                    dp[i][j] = dp[i][j-1]+1;
                prevRow = i;
                numOfCols = dp[i][j]; //the biggest number of cols to have consecutive 1s till this column
                while (prevRow>=0&&matrix[prevRow][j]=='1')
                {
                    //the number of colums to have all 1s till this colums across prevRows to this current row
                    numOfCols = numOfCols>dp[prevRow][j]?dp[prevRow][j]:numOfCols; 
                    a = numOfCols*(i-prevRow+1);
                    maxVal = maxVal>a?maxVal:a;
                    prevRow--;
                }
            }            
        }

        
        return maxVal;
    }
};
