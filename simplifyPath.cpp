class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        string res = "";
        for (int i=0; i<len; i++)
        {
            if (path[i]=='/')
            {
                while ((i+1)<len&&path[i+1]=='/')
                {
                    i++;
                }
                res = res + '/';
            }
            if (path[i]=='.')
            
        }
    }
};
