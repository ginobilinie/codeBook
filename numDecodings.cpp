class Solution {
public:
    int numDecodings(string s) {
        // vector<int> dp;
        if (s=="")
            return 0;
        int len = s.length();
        
        // int i=0;
        // while (i<len&&s[i]=='0')
        //     i++;
        // if (i>=len)
        //     s="";
        // else
        //     s = s.substr(i);
        // if (s=="")
        //     return 0;
        // len = s.length();    
        
        if (s[0]=='0')
            return 0;
        if (len==1)
            return 1;
        vector<int> dp(len,0);
        dp[0] = 1;
        
        if (len>=2)
        {
            int d = (s[0]-'0')*10 + s[1]-'0';
            if (d<27)
            {
                dp[1] = 2;
                if (s[1]=='0')
                {
                    dp[1] = 1;  
                    s[1] = '9';
                }
            }
            else
            {
                dp[1] = 1;
                if (s[1]=='0')
                {
                    dp[1] = 0;
                    return 0;
                }

            }
        }
        for (int i=2; i<len; i++)
        {
            int d = (s[i-1]-'0')*10 + s[i]-'0';
            if (d<27&&d>0)
            {
                if (s[i]=='0')
                {
                     dp[i] = dp[i-2];
                     s[i]='9';
                }
                else        
                    dp[i] = dp[i-2]+dp[i-1];            
            }
            else if (d>=27)
            {
                if (s[i]=='0')
                {
                    dp[i] = 0;
                    return 0;
                }
                else
                    dp[i] = dp[i-1];                       
            }
            else //d==0
            {
                return 0;
            }
     
        }
        return dp[len-1];
    }
};
