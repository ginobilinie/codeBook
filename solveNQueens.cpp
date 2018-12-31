class Solution {
public:
    vector<vector<bool>> used;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        for (int i=0; i<n; i++)
        {
            vector<bool> tmp;   
            for (int j=0; j<n; j++)
            {
                tmp.push_back(0);
            }
            used.push_back(tmp);
        }
        dfs(0, n);
        return res;
    }
    
    void dfs(int m, int n)//m means the current row index
    {
        string str="";
        if (n==m)
        {
            vector<string> strvec;
            for (int i=0; i<n; i++)
            {
                str = "";
                for (int j=0; j<n; j++)
                {
                    if (used[i][j])
                    {
                        str = str+"Q";
                        // used[i][j] = 0;
                    }
                    else
                    {
                        str = str+".";
                    }
                }
                strvec.push_back(str);
            }
            res.push_back(strvec);
            return;
        }
        
        for (int i=0; i<n; i++)//means find the correct column to place the current (row m) queen
        {
            if (checkPuzzle(m,i,n))
            {
                used[m][i] = 1;
                dfs(m+1,n);
                used[m][i] = 0;
            }
        }
    }
    
  bool checkPuzzle(int row, int col, int n)
    {
        for (int i=0; i<col; i++)
        {
            if (used[row][i])
                return false;
        }
        for (int i=0; i<row; i++)
        {
            if (used[i][col])
                return false;
        }
        
        int r = row, c = col;
        while (--r>-1&&++c<n)
        {
            if (used[r][c])
                return false;
        }
        // r = row;
        // c = col;
        // while (++r<n&&--c>-1)
        // {
        //     if (used[r][c])
        //         return false;
        // }
        r = row;
        c = col;
        while (--r>-1&&--c>-1)
        {
            if (used[r][c])
                return false;
        }
        // r = row;
        // c = col;
        // while (++r<n&&++c<n)
        // {
        //     if (used[r][c])
        //         return false;
        // }
        return true;
    }
};
