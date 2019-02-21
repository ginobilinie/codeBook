class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int sz = rows*cols;
        
        int l=0, r=sz-1, mid;
        int row, col;
        while(l<=r)
        {
            mid = (l+r)/2;
            row = mid/cols;
            col = mid%cols;
            if (row>=rows||col>=cols)
                break;
            if (matrix[row][col]==target)
            {
                return true;
            }
            else if (matrix[row][col]<target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return false;
    }
};
