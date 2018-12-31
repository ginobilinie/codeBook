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
                        used[i][j] = 0;
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
        for (int i=0; i!=col&&i<n; i++)
        {
            if (used[row][i])
                return false;
        }
        for (int i=0; i!=row&&i<n; i++)
        {
            if (used[i][col])
                return false;
        }
        if (row==col)
        {
            for (int i=0; i!=row&&i<n; i++)  
            {
                if (used[i][i])
                    return false;
            }
        }
        return true;
    }
