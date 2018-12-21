class Solution {
public:
    
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs("",n,0,0);
        return res;
    }
    
    void dfs(string s, int n, int left, int right)//left: # of openning braket, right: # of closing braket
    {
        if (left==n&&right==n)
        {
            res.push_back(s);
            return;
        }
        if (left<right)//invalid case
            return;
        if (left<n)
        {
            string tmp = s;
            s = s+'(';
            left++;
            dfs(s,n,left,right);
            left--;
            s = tmp;
        }
        if (right<n)
        {
            string tmp = s;
            s = s + ')';
            right++;
            dfs(s,n,left, right);
            right--;
            s = tmp;
        }
    }
};
