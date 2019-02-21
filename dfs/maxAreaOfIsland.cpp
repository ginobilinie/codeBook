class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> used(rows,vector<bool>(cols,0));
        int maxArea = 0;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
            {
                if (!used[i][j]&&grid[i][j]==1) 
                {
                    int cnt = 1;
                    used[i][j] = 1;
                    dfs(grid,used,i,j,cnt);
                    cout<<cnt<<endl;
                    if (cnt>maxArea)
                        maxArea = cnt;
                }
            }
        return maxArea;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& used, int x, int y, int& cnt)
    {
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        for (int i=0; i<4; i++)
        {
            int px = x + dx[i];
            int py = y + dy[i];
            if (px<0||px>=grid.size()||py<0||py>=grid[0].size()||used[px][py]||grid[px][py]==0)
                continue;
            used[px][py] = 1;
            cnt++;
            dfs(grid,used,px,py,cnt);
        }
    }
};
