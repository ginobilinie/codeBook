class Solution {
public:
    string countAndSay(int n) {
     string res="1";
     if (n==1)
         return res;
     for (int i=2; i<=n; i++)
     {
         res = subCountSay(res);
     }
     return res;
    }
    string subCountSay(string s)
    {
        int len = s.length();
        string res = "";
        char currDigit = s[0];
        int count = 1;
        if (len==1)
            return "11";
        for (int i=1; i<len; i++)
        {
            if (s[i]==currDigit)
            {
                count++;
            }else
            {
                char cc = '0'+count;
                res = res+cc;
                res = res+currDigit;
                currDigit = s[i];
                count = 1;
            }
        }
        char cc = '0'+count;
        res = res+cc;
        res = res+currDigit;
        return res;
    }
};
