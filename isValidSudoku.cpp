class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];
        
        for (int i=0; i<9; i++)
        {
            memset(used,0,9*sizeof(bool));
            for (int j=0; j<9; j++)
            {
                char pos = board[i][j];
                if (pos=='.')
                    continue;
                if (used[pos-'1'])
                    return false;
                used[pos-'1'] = 1;
            }
        }

        for (int i=0; i<9; i++)
        {
            memset(used,0,9*sizeof(bool));
            for (int j=0; j<9; j++)
            {
                char pos = board[j][i];
                if (pos=='.')
                    continue;
                if (used[pos-'1'])
                    return false;
                used[pos-'1'] = 1;
            }
        }
        
        for (int i=1; i<8; i++)
        {
            for (int j=1; j<8; j++)
            {
                memset(used,0,9*sizeof(bool));
                for (int m=-1; m<2; m++)
                {
                    for (int n=-1; n<2; n++)
                    {
                        char pos = board[i+m][j+n];
                        if (pos=='.')
                            continue;
                        if (used[pos-'1'])
                            return false;                        
                        used[pos-'1'] = 1;
                    }
                }

            } 
        }

        return true;
    }
};
