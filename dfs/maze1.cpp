class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
       if (maze.empty()||maze[0].empty()) return 1;
        int rows = maze.size();
        int cols = maze[0].size();
        // maze[start[0]][start[1]] = -1;
        bool flag = 0;
        dfs(maze,start[0],start[1], destination, flag);
        return flag;
    }
    
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void dfs(vector<vector<int>>& maze, int x, int y, vector<int>& des, bool& flag)
    {
        if (x==des[0]&&y==des[1]) 
        {
            flag = 1;
            return;
        }
        maze[x][y] = -1;//visited
        for (int i=0; i<4; i++)
        {
            int px = x + dx[i], py = y+dy[i];
            while (px<maze.size()&&px>=0&&py<maze[0].size()&&py>=0&&maze[px][py]!=1)
            {
                px += dx[i];
                py += dy[i];
            }
            px -= dx[i];
            py -= dy[i];
            if (maze[px][py]!=-1)
                dfs(maze,px,py,des,flag);
            if (flag)
                return;
        }
    }
      
};
