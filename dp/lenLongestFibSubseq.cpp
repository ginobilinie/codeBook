class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        vector<vector<int>> dp(A.size(),vector<int>(A.size(),0));//dp[i][j] to record the max length of including a[i] and [j]
        unordered_map<int,int> locdict;
        for (int i=0; i<A.size(); i++)
        {
            locdict[A[i]] = i;
        }
        
        int res = 0;
        for (int i=2; i<A.size(); i++)
        {
            for (int j=i-1; j>-1; j--)
            {
                int smallerVal = A[i]-A[j];//check the tuple [smallerVal, j, i] is the Fibonacci subsequence or not 
                if (smallerVal<A[j]&&locdict.count(smallerVal))
                {
                    int smallerInd = locdict[smallerVal];
                    if (dp[j][smallerInd])
                        dp[i][j] = max(dp[i][j],dp[j][smallerInd]+1);  
                    else
                        dp[i][j] = 3;
                }
                if (dp[i][j]>res)
                    res = dp[i][j];
            }
        }
        return res;
    }
};
