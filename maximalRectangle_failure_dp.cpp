class Solution {
public:
    struct pos
    {
        int x;
        int y;
        pos(int a, int b):x(a),y(b){}
    };
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<struct pos>> dp;
        vector<struct pos> tmp;
        for (int i=0; i<rows; i++)
        {    
            for (int j=0; j<cols; j++)
            {
                if (matrix[i][j]=='1')
                {
                    struct pos a(i,j);
                    tmp.push_back(a);             
                }
                else
                {
                    struct pos a(-1,-1);
                    tmp.push_back(a);                    
                }

            }
            dp.push_back(tmp);
            tmp.clear();
        }
        
        for (int i=1; i<cols; i++)
        {
            if (matrix[0][i]=='1'&&dp[0][i-1].x!=-1)
            {
                dp[0][i] = dp[0][i-1];
            }
        }
        
        int maxVal = 0;
        for (int i=1; i<rows; i++)
        {
            if (matrix[i][0]=='1'&&dp[i-1][0].x!=-1)
            {
                dp[i][0] = dp[i-1][0];
            }
        }
        for (int i=1; i<rows; i++)
        {
            for (int j=1; j<cols; j++)
            {
                bool flag1 = 1, flag2 =1;
                if (matrix[i][j]=='1'&&dp[i][j-1].x!=-1)
                {
                    int x0 = dp[i][j-1].x;
                    int y0 = dp[i][j-1].y;
                    // bool flag = 1;
                    for (int k=x0; k<i; k++)
                    {
                        if (matrix[k][j]!='1')
                        {
                            flag1 = 0;
                            break;
                        }
                    }
                    if (flag1)
                    {
                        dp[i][j] = dp[i][j-1];
                    }
                }
                
                if (matrix[i][j]=='1'&&dp[i-1][j].y!=-1)
                {
                    int x0 = dp[i-1][j].x;
                    int y0 = dp[i-1][j].y;
                    // bool flag = 1;
                    for (int k=y0; k<j; k++)
                    {
                        if (matrix[i][k]!='1')
                        {
                            flag2 = 0;
                            break;
                        }
                    }
                    if(flag2)
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
                
                if (matrix[i][j]=='1'&&dp[i-1][j].y!=-1&&dp[i][j-1].y!=-1&&flag1&&flag2)
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                
                // int val = 0;
                if (dp[i][j].x!=-1)
                {
                    int val = (i-dp[i][j].x+1)*(j-dp[i][j].y+1);
                    if (maxVal>val)
                        maxVal = val;
                }
            }
        }
        return maxVal;
    }
};
