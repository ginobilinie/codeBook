class Solution {
public:
    int res = 0;
    int numDistinct(string s, string t) {
        dfs(s, t, 0, 0);
        return res;
    }
    void dfs(string &s, string &t, int inds, int indt)
    {
        if (indt==t.length())
        {
            res++;
            return;
        }
        for (int i=inds; i<s.length(); i++)
        {
            if (s[i]==t[indt])
            {
                dfs(s,t,i+1,indt+1);
            }
        }
    }
};
