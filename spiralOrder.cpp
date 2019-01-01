class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0, right = cols -1;
        int top = 0, down = rows -1;
        
        while (left<=right&&top<=down)
        {
            //from left to right
            int currRow = top;
            for (int i=left; i<=right; i++)
            {
                res.push_back(matrix[currRow][i]);
            }
            //from top to down
            int currCol = right;
            for (int i=top+1; i<=down; i++)
            {
                res.push_back(matrix[i][currCol]);
            }
            //from right to left
            currRow = down;
			if (top==down)
				break;
            for (int i=right-1; i>=left; i--)
            {
                res.push_back(matrix[currRow][i]);
            }
            //from down to top
            currCol = left;
			if (left==right)
				break;
            for (int i=down-1; i>top; i--)
            {
                res.push_back(matrix[i][currCol]);
            }
            left++;
            right--;
            top++;
            down--;
        }
        return res;
    }
};
