class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int res = 0;
        vector<vector<bool>> used(grid.size(),vector<bool>(grid[0].size(),0));
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[0].size(); j++)
            {
                // cout<<i<<" "<<j<<" ";
                if (!used[i][j]&&grid[i][j]=='1')
                {
                    dfs(grid, i, j, used);
                    res++;                   
                }
            }
        return res;
    }
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    void dfs(vector<vector<char>>& grid, int currRow, int currCol, vector<vector<bool>> &used)
    {
        if (grid[currRow][currCol]=='0')
        {
            return;
        }
        // cout<<currRow<<" "<<currCol<<endl;
        used[currRow][currCol] = 1;
        for (int i=0; i<4; i++)
        {
            int nextRow = currRow + dx[i];
            int nextCol = currCol + dy[i];
            if (nextRow>=grid.size()||nextRow<0||nextCol>=grid[0].size()||nextCol<0)
                continue;
            if (!used[nextRow][nextCol]&&grid[nextRow][nextCol]=='1')
                dfs(grid, nextRow, nextCol, used);
        }
    }
};
