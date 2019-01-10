class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1+len2!=s3.length())
            return false;
        vector<vector<bool>> dp(len1+1,vector<bool>(len2+1,0));
        //dp[i][j] means using the first i characters from s1 and the first j characters from s2 can
        // interleaved form s3[i+j-1] or not.
        dp[0][0] = 1;
        for (int i=1; i<len1+1; i++)
        {
            dp[i][0] = (s3.substr(0,i)==s1.substr(0,i));
        }
        for (int i=1; i<len2+1; i++)
        {
            dp[0][i] = (s3.substr(0,i)==s2.substr(0,i));
        }
        
        for (int i=1; i<len1+1; i++)
        {
            for (int j=1; j<len2+1; j++)
            {
                if (s3[i+j-1]==s2[j-1]&&dp[i][j-1] || s3[i+j-1]==s1[i-1]&&dp[i-1][j])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }
        return dp[len1][len2];
    }
};
