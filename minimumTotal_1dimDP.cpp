class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty())
            return 0;
        // vector<vector<int>> dp = triangle;
        vector<int> curr;
        vector<int> prev;
        int minVal = INT_MAX;
        
        prev = triangle[0];
        curr = triangle[0];
        for (int i=1; i<triangle.size(); i++)
        {
            vector<int> line = triangle[i];
            curr = line;
            curr[0] = curr[0] + prev[0];
            curr[line.size()-1] = prev[line.size()-2] + curr[line.size()-1];
            for (int j=1; j<line.size()-1; j++)
            {
                curr[j] = curr[j] + (prev[j]<prev[j-1]?prev[j]:prev[j-1]);
            }
            prev = curr;
        }
        for (int i=0; i<curr.size(); i++)
        {
            if (curr[i]<minVal)
                minVal = curr[i];
        }
        return minVal;
    }
};
