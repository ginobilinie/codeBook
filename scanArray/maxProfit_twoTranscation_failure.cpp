class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ind, maxPrice=0, minPrice=0, totalProfit=0, sz;
        sz = prices.size();
        ind = 0;
        int mostProfit = 0, secondProfit = 0;
        while (ind<sz-1)
        {
            while (ind<sz-1 && prices[ind+1]<=prices[ind]) ind++;
            minPrice = prices[ind];
            while (ind<sz-1 && prices[ind+1]>=prices[ind]) ind++;
            maxPrice = prices[ind];
            int currGap = maxPrice - minPrice;
            if (currGap>mostProfit)
            {
                secondProfit = mostProfit;
                mostProfit = currGap;
            }
            else if (currGap>secondProfit)
            {
                secondProfit = currGap;
            }
        }
        return mostProfit+secondProfit;
    }
};
