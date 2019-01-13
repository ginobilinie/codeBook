class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int maxVal=0,  minPrice=INT_MAX;
        for (int i=0; i<prices.size(); i++)
        {
            minPrice = minPrice<prices[i]?minPrice:prices[i];
            int profit = prices[i] - minPrice;
            maxVal = maxVal>profit?maxVal:profit;
        }
        return maxVal;
        // return 0;
    }
};
