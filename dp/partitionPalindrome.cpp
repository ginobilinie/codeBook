class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        if (s=="")
            return {};
        int len = s.length();
        vector<vector<bool>> dp(len,vector<bool>(len,0));
        
        for (int i=0; i<len; i++)
            dp[i][i] = 1;
        
        for (int i=0; i<len-1; i++)
        {
            if (s[i]==s[i+1])
                dp[i][i+1] = 1;
        }
        
        for (int k=3; k<len+1; k++)
        {
            for (int i=0; i<len-k+1; i++)
            {
                int j = i+k-1;//i,...j, i,j included
                if (s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1];
            }
        }
        
        //now we have whether s[i...j] is palindrome or not
       //then we can use dfs to search it
        vector<string> tmp;
        dfs(s,dp,0,tmp);
        return res;
    }
    
    void dfs(string s, vector<vector<bool>>& dp, int startInd, vector<string>& vec)
    {
        if (startInd==s.length())
        {
            res.push_back(vec);
            return;
        }
        for (int i=startInd; i<s.length(); i++)
        {
            if (dp[startInd][i])
            {
                vec.push_back(s.substr(startInd,i-startInd+1));
                dfs(s,dp,i+1,vec);
                vec.pop_back();
            }
        }
    }
};
