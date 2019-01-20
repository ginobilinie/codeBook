class Solution {
public:
    
    struct loc
    {
        int x;
        int y;
        //loc(int a, int b):x(a),y(b){}
    };
    int rows, cols;
   // set<vector<loc>> myset;

    int uniquePathsIII(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        rows = grid.size();
        cols = grid[0].size();
        vector<struct loc> currPath;
        loc currLoc, end;
        bool flag1=0, flag2=0;
		vector<vector<bool>> used(rows,vector<bool>(cols,0));
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
            {
                if (grid[i][j]==1)
                {
                    currLoc.x = i;
                    currLoc.y = j;
                    flag1 = 1;
                }
                if (grid[i][j]==2)
                {
                    end.x = i;
                    end.y = j;
                    flag2 =1;
                }
				   if (grid[i][j]==-1)
                    used[i][j] = 1;
            }
           if (flag1&&flag2)
                break;
        }
        if (!flag1||!flag2)
            return 0;
        // currPath.push_back(currLoc);
        
        used[currLoc.x][currLoc.y] = 1;     
        // dfs(grid, currLoc, end, currPath, used);
		int res = 0;
        dfs(grid, currLoc, end, used, res);

        // return myset.size();
        return res;
    }
    
    int dx[4] ={-1,0,1,0};
    int dy[4] ={0,1,0,-1};
    // void dfs(vector<vector<int>>& grid, struct loc currLoc, struct loc end, vector<struct loc>& currPath, vector<vector<bool>>& used)
    void dfs(vector<vector<int>>& grid, loc currLoc, loc end, vector<vector<bool>>& used, int& res)
    {
        if (currLoc.x==end.x&&currLoc.y==end.y)
        {
            // currPath.push_back(end);
            bool flag = 1;//1: all visited, 0: not all visited
            for (int i=0; i<grid.size(); i++)
            {
                for (int j=0; j<grid[0].size(); j++)
                {
                    if (!used[i][j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (!flag)
                    break;
            }
            if (flag)
            {
                //myset.insert(currPath);
                res = res+1;
            }
            return;
        }
        for (int i=0; i<4; i++)
        {
            int px = currLoc.x+dx[i];
            int py = currLoc.y+dy[i];
            if (checkValid(px, py, rows, cols)&&grid[px][py]!=-1&&!used[px][py])
            {
                // struct loc tmp = currLoc;
                currLoc.x = px;
                currLoc.y = py;
                // currPath.push_back(currLoc);
                used[px][py] = 1;
                // dfs(grid, currLoc, end, currPath, used);
                dfs(grid, currLoc, end, used, res);

                //currPath.pop_back();
                currLoc.x -= dx[i];
                currLoc.y -= dy[i];
                used[px][py] = 0;
            }
        }
    }
    
    bool checkValid(int x, int y, int rows, int cols)
    {
        if (x<0||x>=rows||y<0||y>=cols)
            return 0;
        return 1;
    }
};
