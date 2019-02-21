class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()||matrix[0].empty())
            return false;
        int rows = matrix.size(), cols = matrix[0].size();
        //we can have O(m*logn) method and also O(m+n) method
        
        //now we write O(m+n) method
        int row = rows - 1, col = 0;
        while (row>=0&&col<cols)
        {
            if (matrix[row][col]==target)
            {
                return 1;
            }
            else if (matrix[row][col]<target)
            {
                col++;//we have excluded one column
            }
            else
            {
                row--;//we have excluded one row
            }
        }
        return false;
    }
};
