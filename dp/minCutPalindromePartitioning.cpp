class Solution {
public:
    int skips = 0;
    int minCut(string s) {
        if (s=="")
            return 0;
        int len = s.length();
        vector<vector<bool>> dp(len,vector<bool>(len,0));
        for (int i=0; i<len; i++)
            dp[i][i] = 1;
        for (int i=0; i<len-1; i++)
            if (s[i]==s[i+1])
                dp[i][i+1] = 1;
        for (int k=3; k<len+1; k++)
        {
            for (int i=0; i<len-k+1; i++)
            {
                int j = i+k-1;
                if (s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1];
            }
        }
        //so far, we have the necessary information about whether s[i...j] is a palindrome or not
        if (dp[0][len-1])
            return 0;
        //bfs or greedy, howeve, it fails when s="aaabaa"
        // int skips = 0;
        // for (int i=0; i<len; i++)
        // {
        //     int ind = i;//records the longest skip point
        //     for (int j=i+1; j<len; j++)
        //     {
        //         if (dp[i][j])
        //             ind = j;
        //     }
        //     if (ind==len-1)
        //         break;
        //     skips++;
        //     i = ind;
        // }
        bfs(s, dp, 0);
        return skips;
    }
    
    void bfs(string s, vector<vector<bool>>& dp, int currInd)
    {
        queue<int> myq;
        myq.push(0);
        // skips++;
        while (!myq.empty())
        {
            int qsz = myq.size();
            for (int k=0; k<qsz; k++)
            {
                int currInd = myq.front();
                myq.pop();
                if (currInd==s.length()-1)
                    return;
               for (int i=currInd; i<s.length(); i++)
                {
                   if (dp[currInd][i])
                   {
                       if (i+1<s.length())
                        myq.push(i+1);
                        else
                            return;
                       dp[currInd][i] = 0;//this is very important for the prunning.
                   }
                }            
              
            }
          skips++;
        }
    }
};
