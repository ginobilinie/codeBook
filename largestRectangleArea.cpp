class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        int sz = heights.size();
        //vector<vector<int>> dp(sz,vector<int>(sz,0));
        int minVal, maxVal=INT_MIN;
        for (int i=0; i<sz; i++)
        {
            //dp[i][i] = heights[i];
            minVal = heights[i];
            if (heights[i]>maxVal)
                maxVal = heights[i];
            for (int j=i+1; j<sz; j++)
            {
                if (heights[j]<minVal)
                    minVal = heights[j];
                int tmp = minVal*(j-i+1);
                if (tmp>maxVal)
                    maxVal = tmp;
            }
        }
        return maxVal;
    }
};
