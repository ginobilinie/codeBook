class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s=="")
            return 0;
        int len = s.length();
        int pos = s.find_last_of(" ");
        if (pos == -1)
        {
            return s.length();
        }
        if (pos==len-1)
        {
            int i,j;
            for (i=len-2; i>-1; i--)
            {
                if (s[i]!=' ')
                    break;
            }
            if (i==-1)
                return 0;
            int cnt = 0;
            for (j = i; j>-1; j--)
            {
                if (s[j]==' ')
                    break;
                cnt++;
            }
            return cnt;
        }
        return len-1-pos; 
    }
};
