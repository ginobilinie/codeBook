class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        mat.resize(n);
        for (int i=0; i<n; i++)
        {
            mat[i].resize(n,-1);
        }
        sz = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        mat[row][col] = player;
        bool flag = 0;
        int i;
        for (i=0; i<sz; i++)
            if (mat[row][i]!=player)
                break;
        if (i==sz)
            flag = 1;
        for (i=0; i<sz; i++)
            if (mat[i][col]!=player)
                break;
        if (i==sz)
            flag = 1;
        if (row==col)
        {
            for (i=0; i<sz; i++)
                if (mat[i][i]!=player)
                    break;
            if (i==sz)
                flag = 1;
        }
        if (row==sz-1-col)
        {
            for (i=0; i<sz; i++)
            {
                if (mat[i][sz-1-i]!=player)
                    break;
            }
            if (i==sz)
                flag = 1;
        }
        if (flag)
            return player;
        else
            return 0;
    }
    vector<vector<int>> mat;
    int sz = 0;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
