class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        int len = len1<len2?len1:len2;
        int p1 = len1-1, p2 = len2-1;
        string res = "";
        int c, degree=0;
        while(p1>=0&&p2>=0)
        {
            c = a[p1]-'0'+b[p2]-'0' + degree;
            char tmp = c%2+'0';
            res += tmp;
            degree = c/2;
            p1--;
            p2--;
        }
        while (p1>=0)
        {
            c = a[p1]-'0'+ degree;
            char tmp = c%2+'0';
            res += tmp;
            degree = c/2;
            p1--;            
        }
        while (p2>=0)
        {
            c = b[p2]-'0'+ degree;
            char tmp = c%2+'0';
            res += tmp;
            degree = c/2;
            p2--;            
        }
        if (degree>0)
            res += '1';
        reverse(res.begin(),res.end());
        return res;
    }
};
