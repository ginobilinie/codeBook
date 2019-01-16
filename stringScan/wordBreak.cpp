class Solution {
public:
    bool flag = 0;
    // string currStr="";
    bool wordBreak(string s, vector<string>& wordDict) {
        string currStr = "";
        vector<bool> used(s.length(),0);
        dfs(s,wordDict,currStr, used);
        return flag;
    }
    
    void dfs(string s, vector<string>& wordDict, string currStr, vector<bool>& used)
    {
        if (currStr.length()>s.length())
            return;
        if (s.substr(0,currStr.length())!=currStr)
            return;
        if (used[currStr.length()])//already been here
            return;
        if (currStr==s)
        {
            flag = 1;
            return;
        }
        used[currStr.length()] = 1;
        int sz = wordDict.size();
        // string word;
        for (int i=0; i<sz; i++)
        {
            dfs(s,wordDict,currStr+wordDict[i],used);
            if (flag)
                return;
        }
    }
};
