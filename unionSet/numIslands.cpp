class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int sz = rows*cols;
        vector<int> parent(sz,0);
        // vector<vector<bool>> used(rows,vector<bool>(cols,0));
        for (int i=0; i<sz; i++)
        {
            parent[i] = i;
        }
        int count = 0;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
            {
                if (grid[i][j]=='1')
                    count++;
            }
        // cout<<count<<endl;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
            {
                // if (grid[i][j]=='0'||used[i][j])
                if (grid[i][j]=='0')
                    continue;
                int pos = i*cols + j;
                int p0 = findParent(pos, parent);
                // used[i][j] = 1;
                for (int k=0; k<4; k++)
                {
                    int nextRow = i + dx[k];
                    int nextCol = j + dy[k];
                    if (nextRow>=rows||nextRow<0||nextCol>=cols||nextCol<0||grid[nextRow][nextCol]=='0')
                        continue;
                    int nextPos = nextRow*cols + nextCol;
                    int p1 = findParent(nextPos, parent);
                    // used[nextRow][nextCol] = 1;
                    if (p0!=p1)
                    {
                        //union
                        parent[p1] = p0;
                        count--;
                    }
                }
            }
        }
        
        return count;
    }
    
    int findParent(int key, vector<int>& parent)
    {
        while (key!=parent[key])
        {
            parent[key] = parent[parent[key]];
            key = parent[key];
        }
        return key;
    }
};
