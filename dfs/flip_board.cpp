class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;
        int rows = board.size();
        int cols = board[0].size();
        
        vector<vector<bool>> used(rows,vector<bool>(cols,0));
        //0's row
        //last ros
        for (int i=0; i<cols; i++)
        {
            if (board[0][i]=='O')
            {
                board[0][i] = '#';
                dfs(board,0,i);
            }   
            if (board[rows-1][i]=='O')
            {
                board[rows-1][i] = '#';
                dfs(board,rows-1,i);
            }
        }
    
        //0's column
        //last column
        for (int i=0; i<rows; i++)
        {
            if (board[i][0]=='O')
            {
                board[i][0] = '#';
                dfs(board,i,0);
            }
            if (board[i][cols-1]=='O')
            {
                board[i][cols-1] = '#';
                dfs(board,i, cols-1);
            }
        }
        
        for (int i=1; i<rows-1; i++)
        {
            for (int j=1; j<cols-1; j++)
            {
                if (board[i][j]=='O')
                    board[i][j] = 'X';
            }
        }
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
            {
                if (board[i][j]=='#')
                    board[i][j] = 'O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int row, int col)
    {
        int rows = board.size();
        int cols = board[0].size();
        for (int i=0; i<4; i++)
        {
            int x = row + dx[i];
            int y = col + dy[i];
            if (checkPos(x,y, rows,cols)&&board[x][y]=='O')
            {
                board[x][y] = '#';
                dfs(board,x,y);
            }
        }
    }
    bool checkPos(int x, int y, int rows, int cols)
    {
        if (x>=rows||x<0||y<0||y>=cols)
            return false;
        return true;
    }
};
