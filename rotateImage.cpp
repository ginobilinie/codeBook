class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        int tmp;
        int sz = matrix.size();
        for (int i=0; i<(sz+1)/2; i++)
            for (int j=i; j<(sz-i-1); j++)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[sz-1-j][i];
                matrix[sz-1-j][i] = matrix[sz-1-i][sz-1-j];
                matrix[sz-1-i][sz-1-j] = matrix[j][sz-1-i];
                matrix[j][sz-1-i] = tmp;
            }
        return;
    }
};
