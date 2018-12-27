
class Solution {
public:
 void solveSudoku(vector<vector<char>> &board) {
        int sz = 9;
        bool used[9][9];
        for (int i=0; i<sz; i++)
            for (int j=0; j<sz; j++)
            {
                if (board[i][j]!='.')
                    if (!validateCurrentFill(board,i,j))
                        return;
            }
        solver(board,0);
    }
    bool flag = false;
    //row, col represents the current visit position
    void solver(vector<vector<char>> &board, int index)
    {
        if (index==81)
        {
            flag = 1;
            return;
        }
        if (flag)
            return;
        int row = index/9, col = index - 9*row;

        if (board[row][col]=='.')
        {
			for (int k=1; k<10; k++)// we can set these 9 values to the current position
			{
				board[row][col] = '0'+k;
				bool isValid = validateCurrentFill(board, row, col);
				if (isValid)
				{
					solver(board, index+1);
                    if (flag)
                        return;
					//index--;
					board[row][col] = '.';
				}
				else
				{
					board[row][col] = '.';
				}
			}
        }else
			solver(board, index+1);
        
    }
    
    //we just need to check if the row/col/subbox for this current location is valid or not
    bool validateCurrentFill(vector<vector<char>> &board, int row, int col)
    {
        //check row
        bool used[9];
        memset(used, 0, 9*sizeof(bool));
        for (int i=0; i<9; i++)
        {
            char pos = board[row][i];
           if (pos!='.')
                if (used[pos-'1'])
                    return false;
                else
                    used[pos-'1']=1;
        }
        
        memset(used, 0, 9*sizeof(bool));
        for (int i=0; i<9; i++)
        {
            char pos = board[i][col];
           if (pos!='.')
                if (used[pos-'1'])
                    return false;
                else
                    used[pos-'1']=1;
        }
        
        int startRow=row/3*3, startCol=col/3*3;
        memset(used, 0, 9*sizeof(bool));
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                char pos = board[startRow+i][startCol+j];
               if (pos!='.')
                    if (used[pos-'1'])
                        return false;
                    else
                        used[pos-'1']=1;   
            }
        } 
        return true;
    }
};
