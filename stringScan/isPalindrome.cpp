class Solution {
public:
    bool isPalindrome(string s) {
        if (s=="")
            return true;
        int len = s.length();
        string str ="";
        for (int i=0; i<len; i++)
        {
            if ('a'<=s[i]&&s[i]<='z'||'0'<=s[i]&&s[i]<='9')
            {
                str += s[i];
            }
            else if ('A'<=s[i]&&s[i]<='Z')
            {
                str += ('a' + s[i]-'A');
            }
        }
        
        int l=0, r=str.length()-1;
        bool flag = 1;
        while (l<r)
        {
            if (str[l++]!=str[r--])
            {
                flag = 0;
                break;
            }
        }
        
        return flag;
    }
};
