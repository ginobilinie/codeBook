class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int res = 0;
        int ind = 0;
        while(ind<len)
        {
            res = res*26 + (s[ind++]-'A'+1);
        }
        return res;
    }
};
