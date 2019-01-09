class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1==s2)
            return true;
        if (s1.length()!=s2.length())
            return false;
        int len = s1.length();
        map<char,int> dict;
        for (int i=0; i<len; i++)
        {
            if (dict.count(s1[i])>0)
            {
                dict[s1[i]]++;
            }
            else
            {
                dict[s1[i]] = 1;
            }
        }
        bool flag = 1;
        for (int i=0; i<len; i++)
        {
            if (dict.count(s2[i])>0)
            {
                dict[s2[i]]--;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            for (map<char,int>::iterator iter=dict.begin(); iter!=dict.end(); iter++)
            {
                if (iter->second!=0)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (!flag)
            return false;//here is very important, we cannot else return true;
        
        for (int i=1; i<len; i++)
        {
            if (isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i)))//if not switch
                return true;
            if (isScramble(s1.substr(0,i),s2.substr(len-i))&&isScramble(s1.substr(i),s2.substr(0,len-i)))//if switch
                return true;
        }
        return false;
    }

};
