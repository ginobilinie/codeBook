class Solution {
public:
    #define ID INT_MAX-10
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int i=0; i<rows; i++)
        {
            bool rowZero = false;
            for (int j=0; j<cols; j++)
            {
                if (!matrix[i][j])
                {
                    for (int m=0; m<rows; m++)
                    {
                        if (matrix[m][j])
                            matrix[m][j] = ID;
                    }
                    rowZero = 1;
                }
            }
            if (rowZero)
            {
                for (int m=0; m<cols; m++)
                {
                    if (matrix[i][m])
                        matrix[i][m] = ID;
                }                
            }
        }
        
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
            {
                if (matrix[i][j]==ID)
                    matrix[i][j] = 0;
            }
    }
};
