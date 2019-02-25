class Solution {
public:
    #define minX(x,y) x<y?x:y
    #define minVal(x,y,z) minX(minX(x,y),z)
    int minDistance(string word1, string word2) {
        if (word2=="")
            return word1.length();
        if (word1=="")
            return word2.length();
        int sz1 = word1.length();
        int sz2 = word2.length();
        
        vector<vector<int>> dp(sz1, vector<int>(sz2, 0));
        
        bool flag = 0;

        for (int i=0; i<sz1; i++)
        {
            if (word1[i]==word2[0])
            {
                flag = 1;
            }
            if (flag)
                dp[i][0] = i;  
            else
                dp[i][0] = i+1;
        }
        
        flag = 0;
        for (int i=0; i<sz2; i++)
        {
            if (word1[0]==word2[i])
            {
                flag = 1;
            }
            if (flag)
                dp[0][i] = i;  
            else
                dp[0][i] = i+1;
        }
        
        for (int i=1; i<sz1; i++)
        {
            for (int j=1; j<sz2; j++)
            {
                if (word1[i]==word2[j])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    int tmp = minVal(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
                    dp[i][j] = tmp + 1;
                }
            }
        }
        
        int res = dp[sz1-1][sz2-1];
        return res;  
    }
};
