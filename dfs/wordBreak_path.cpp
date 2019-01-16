class Solution {
public:
    bool flag = 0;
    vector<string> res;
    vector<vector<string>> mat;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<bool> used(s.length(),0);
        string currStr="";
        dfs(s,wordDict,currStr,used);
        vector<string> vec;
        res.clear();
        for (int i=0; i<mat.size(); i++)
        {
            vec = mat[i];
            string str = "";
            for (int j=0; j<vec.size(); j++)
            {
               str += vec[j];
                if (j!=vec.size()-1)
                    str+=" ";
            }
            res.push_back(str);

        }
        return res;
    }
    
    void dfs(string s, vector<string>& wordDict, string currStr, vector<bool>& used)
    {
        if (currStr==s)
        {
            // flag = 1;
            mat.push_back(res);
            return;
        }
        // if (currStr.length()>s.length())
        //     return;
        // if (used[currStr.length()-1])
        //     return;
        for (int i=0; i<wordDict.size(); i++)
        {
            string tmp = currStr+wordDict[i];
            if (tmp.length()>s.length()) continue;
            if (s.substr(0,tmp.length())==tmp)//tle
            //if (s.substr(0,tmp.length())==tmp&&!used[tmp.length()-1])//cannot output all solutions
            {
                used[tmp.length()-1] = 1;
                res.push_back(wordDict[i]);
                dfs(s,wordDict,tmp,used);
                // if (flag)
                    // return;
                res.pop_back();
            }
        }
    }
    
};
