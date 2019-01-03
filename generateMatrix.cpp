class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                tmp.push_back(0);               
            }  
            res.push_back(tmp);
            tmp.clear();
        }


        
        int left = 0, right = n-1;
        int top = 0, down = n-1;
        int currVal = 1;
        int currRow, currCol;
        for (int i=top; i<=down; i++)
        {
            currRow = top;
            // tmp.clear();
            //from left to right
            for (int j=left; j<=right; j++)
            {
                res[currRow][j] = currVal++;
            }
            //from top to down
            currCol = right;
            for (int j=top+1; j<=down; j++)
            {
                res[j][currCol] = currVal++;
            }
            //from right to left
            currRow = down;
            for (int j=right-1; j>=left; j--)
            {
                res[currRow][j] = currVal++;
            }
            //from down to top
            currCol = left;
            for (int j=down-1; j>top; j--)
            {
                res[j][currCol] = currVal++;
            }
            top++;
            down--;
            left++;
            right--;
        }
        vector<vector<int>> vec;
        for (int i=0; i<n; i++)
        {
            tmp.clear();
            for (int j=0; j<n; j++)
            {
                tmp.push_back(res[i][j]);
            }
            vec.push_back(tmp);
        }
        return vec;
    }
};
