class Solution {
public:
    bool flag = 0;
    // string currStr="";
    bool wordBreak(string s, vector<string>& wordDict) {
        string currStr = "";
        dfs(s,wordDict,currStr);
        return flag;
    }
    
    void dfs(string s, vector<string>& wordDict, string currStr)
    {
        if (currStr.length()>s.length())
            return;
        if (s.substr(0,currStr.length())!=currStr)
            return;
        if (currStr==s)
        {
            flag = 1;
            return;
        }
        int sz = wordDict.size();
        // string word;
        for (int i=0; i<sz; i++)
        {
            dfs(s,wordDict,currStr+wordDict[i]);
            if (flag)
                return;
        }
    }
};
