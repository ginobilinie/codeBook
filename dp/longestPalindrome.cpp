class Solution {
public:
    string longestPalindrome(string s) {
      //in the first version, I wrtie a simple scan method which scans from left to right
        //and take i as the middel (odd case) to check the longest palindromic substring
        //also, I consider the even case to check the longest palindromic substring
        
        /*in this version, we can write it a dp problem
        dynamic status convert equation: 
        consider a substring with len-length
        dp[i][j] = {1;//i==j dp[i+1][j-1];//s[i]==s[j] 0//s[i]!=s[j]}
        initialization: dp[i][i] and dp[i][i+1]
        and we can consider from len=3 to len to s.length()
        */
        
        if (s=="")
            return "";
        int len = s.length();
        vector<vector<bool>> dp(len,vector<bool>(len,0));
        
        //left index and maxLen
        int leftInd = 0;
        int maxLen = 1;
        
        //initialization
        for (int i=0; i<len; i++)
            dp[i][i] = 1;
        for (int i=1; i<len; i++)
            if (s[i-1]==s[i])
            {
                dp[i-1][i] = 1;
                maxLen = 2;
                leftInd = i-1;
            }
        
        for (int k=3; k<=len; k++)
        {
            for (int i=0; i<len-k+1; i++)
            {
                int j = i+k-1;
                if (s[i]==s[j])
                {
                     dp[i][j] = dp[i+1][j-1];
                    if (dp[i][j])
                    {
                         maxLen = k;
                        leftInd = i;                        
                    }

                }
                else
                    dp[i][j] = 0;
            }
        }
        
        string res = s.substr(leftInd,maxLen);
        return res;
    }
};
