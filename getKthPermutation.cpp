class Solution {
public:
    string res="";
    bool used[9];
    string getPermutation(int n, int k) {
        int cnt = 0;
        string s="";
        char c;
        // for (int i=1; i<n+1; i++)
        // {
        //     char c = '0'+i;
        //     string s = s + c;
        memset(used,0,9*sizeof(bool));
        dfs(n, s, cnt, k);  
        // }

        return res;
    }
    void dfs(int n, string s, int& cnt, int k)
    {
        if (s.length()==n)
        {
            cnt++;
            if (cnt==k)
            {
                res = s;
                return;
            }
            s="";
            return;
        }
        for (int i=0; i<n; i++)
        {
            if (!used[i])
            {
                string tmp = s;
                char c = '0'+i+1;
                used[i] = 1;
                s = s + c;
                dfs(n, s, cnt, k);
                if (cnt==k)
                    return;
                s = tmp;
                used[i] = 0;
            }
        }
    }
};
