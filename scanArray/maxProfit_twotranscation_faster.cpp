class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int sz = prices.size();
        int ind = 0;
        int totalProfit = 0;
        
        vector<int> scan1(sz,0);
        vector<int> scan2(sz,0);
        //scan from left to right
        int currMin = INT_MAX;
        int gap1 = 0;
        for (int i=0; i<sz; i++)
        {
            if (prices[i]<currMin)
                currMin = prices[i];
            if (gap1<prices[i]-currMin)
                gap1 = prices[i] - currMin;
            scan1[i] = gap1;
        }
        //scan from right to left
        int currMax = INT_MIN;
        int gap2 = 0;
        for (int i=sz-1; i>-1; i--)
        {
            if (prices[i]>currMax)
                currMax = prices[i];
            if (gap2<currMax-prices[i])
                gap2 = currMax - prices[i];
            scan2[i] = gap2;
        }
        
        for (int i=1; i<sz; i++)
        {
            if (totalProfit<scan1[i-1]+scan2[i])
                totalProfit = scan1[i]+scan2[i];
        }
        
        totalProfit = totalProfit<scan1[sz-1]?scan1[sz-1]:totalProfit;
        totalProfit = totalProfit<scan2[0]?scan2[0]:totalProfit;
        
        return totalProfit;
    }
};
