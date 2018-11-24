class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        int minV = INT_MAX;
        if (len==0)
            minV = 0;
        string res = "";
        for (int i=0; i<len; i++)
        {
            if (strs[i].length()<minV)
                minV = strs[i].length();
        }
        for (int i=0; i<minV; i++)
        {
            char base = strs[0][i];
            bool flag = true;
            for (int j=1; j<len; j++)
            {
                if (strs[j][i]==base)
                    continue;
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res = res + base;
            else
                break;
        }
        return  res;
    }
};
