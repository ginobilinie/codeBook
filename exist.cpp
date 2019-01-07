class Solution {
public:
    bool res = 0;
    vector<vector<bool>> used;
    int rows, cols;
    int horizonturn[4] = {0,0,-1,1};
    int verticalturn[4] = {1,-1,0,0};
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        rows = board.size();
        cols = board[0].size();
        for (int i=0; i<rows; i++)
        {
            vector<bool> tmp;
            for (int j= 0; j<cols; j++)
            {
                tmp.push_back(0);
            }      
            used.push_back(tmp);
        }
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
            {
                 dfs(board, i, j, word, 0);
                if (res)
                    break;
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<char>>& board,  int row, int col, string word, int ind4word)
    {
        if (res)
            return;
        if (ind4word==word.length())
        {
            res = true;
            return;
        }

        if (row<0||row>=rows||col<0||col>=cols)
            return;

        // int row = ind4board/cols, col = ind4board%cols;

            if (!used[row][col] && board[row][col]==word[ind4word])
            {
                used[row][col] = 1;
                for (int m=0; m<4; m++)
                    dfs(board, row+horizonturn[m], col+verticalturn[m], word, ind4word+1);
                used[row][col] = 0;
            }
     
    }
};
