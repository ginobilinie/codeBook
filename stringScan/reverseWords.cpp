class Solution {
public:
    void reverseWords(string &s) {
       int len = s.length();
        stack<string> mys;
        string res = "";
        for (int i=0; i<len; i++)
        {
            while (i<len&&s[i]==' ')
            {
                i++;
            }
            string word = "";
            while(i<len&&s[i]!=' ')
            {
                word += s[i];
                i++;
            }
            if (word!="")
                mys.push(word);
        }
        while (!mys.empty())
        {

                res += mys.top()+" ";
            mys.pop();
        }
        if (res[res.length()-1]==' ')
            res = res.substr(0,res.length()-1);
        s = res;
    }
};
