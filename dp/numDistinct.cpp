class Solution {
public:
    int numDistinct(string s, string t) {
        //any s can have eact one match of "" (the end of s have a "")
        //use or not use the current match
        //we can only use the previous match, since we cannot use the current match
        
        int sz_s = s.length();
        int sz_t = t.length();
        
        //index 0 means this char: "" for both s and t
        vector<vector<int>> dp(sz_s+1, vector<int>(sz_t+1, 0));
        
        for (int i=0; i<sz_s; i++)//any string can match ""
            dp[i][0] = 1;
        
        for (int i=0; i<sz_s; i++)
            for (int j=0; j<sz_t; j++)
            {
                if (s[i]==t[j])
                    dp[i+1][j+1] = dp[i][j+1] + dp[i][j];
                //dp[i][j+1] means we donot use s[i] to match t[j], then the result should be s[i-1] match t[j]
                //dp[i][j] means we use s[i] to match t[j], the result should be same with s[i-1] match t[j-1]
                else
                    dp[i+1][j+1] = dp[i][j+1];
                //since we cannot use s[i] to match t[j], then we should use s[i-1] to match t[j], so it is dp[i][j+1]
            }
        int res = dp[sz_s][sz_t];
       return res;
    }
    
};
