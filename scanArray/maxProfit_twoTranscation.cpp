class Solution {
public:
    int maxProfit_twoTranscation.cpp(vector<int>& prices) {
        int sz = prices.size();
        int ind = 0;
        int totalProfit = 0;
        for (; ind<sz; ind++)//ind partitio the array to two parts, ind included to the right side
        {
            //for left part
            int currMin = INT_MAX, gapLeft = 0;
            for (int i=0; i<ind; i++)
            {
                if (prices[i]<currMin)
                    currMin = prices[i];
                if (prices[i]-currMin>gapLeft)
                    gapLeft = prices[i] - currMin;
            }
            //for the right part
            currMin = INT_MAX;
            int gapRight = 0;
            for (int i=ind; i<sz; i++)
            {
                if (prices[i]<currMin)
                    currMin = prices[i];
                if (prices[i]-currMin>gapRight)
                    gapRight = prices[i] - currMin;
            }
            if (gapLeft+gapRight>totalProfit)
                totalProfit = gapLeft+gapRight;
        }
        return totalProfit;
    }
};
