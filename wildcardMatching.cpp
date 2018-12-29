class Solution {
public:
    bool isMatch(string s, string p) {
        bool res = true;
        int lenP = p.length();
        int lenS = s.length();
        int indP=0, indS=0;
        while (indP<lenP)
        {
            while (indP<lenP&&('a'<p[indP] && p[indP]<'z'||p[indP]=='?') && indS<lenS)
            {
                if (p[indP]!=s[indS]&&p[indP]!='?')
                    return false;
                else
                {
                    indP++;
                    indS++;
                }
            }
            //indP is '*'
            if (indP<lenP)
            {
                if (indS==lenS)
                {
                    for (int i=indP; i<lenP; i++)
                        if (p[indP]!='*')
                            return false;
                    return true;
                }else
                {
                    while (indP<lenP&&p[indP]=='*')
                        indP++;
                }
            }
        }

        return res;
    }
};
