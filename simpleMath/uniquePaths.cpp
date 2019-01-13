class Solution {
public:
    long long uniquePaths(long long m, long long n) {
       //result is C(m-1+n-1,m-1)
        long long res = 1;
        long long totalSteps = m - 1 + n - 1;
        long csteps = n<m?n-1:m-1;
        long long div = 1;
        if (m==0 ||n==0)
            return 0;
		int kk = csteps;
		int tt = totalSteps;
        while (csteps)
        {
            if (totalSteps%(kk-csteps+1)==0)
                res *= totalSteps/(kk-csteps+1);
            else
            {
                res *= totalSteps;
                div *= (kk-csteps+1);
                if (res%div==0)
                {
                    res = res/div;
                    div = 1;
                }
            }
            csteps--;
            totalSteps--;
        }
        if (div!=1)
            res/=div;
        return res;
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[100][100];
        for (int i=0; i<m; i++)
            dp[0][i] = 1;
        for (int j=0; j<n; j++)
            dp[j][0] = 1;
        for (int i=1; i<n; i++)
            for (int j=1; j<m; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        int res = dp[n-1][m-1];
        return res;
    }
};
