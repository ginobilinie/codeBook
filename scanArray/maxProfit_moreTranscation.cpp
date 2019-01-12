class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
       /*
       A greedy algorithm.
       for the current visited pointer, we find the first item of the first rigorously increased sequence, 
       which is actually the minPrice from the current pointer on. Starting from this minPrice, we find the first 
       item of the first rigorously decreased sequence, which is actually the maxPrice from the minPrice on. Thus,
       the biggest profit in this margin is maxVal - minVal. Then we move the pointer on to neighbor of the maxPrice pointer.
       And continue this process. Actually, we can easily prove that this method can give the max total profit.
       */
        int totalProfit = 0, minPrice=0, maxPrice=0, tmp, ind, sz=prices.size();
        ind = 0;//current pointer
        while (ind<sz-1)
        {
            //find the first item of the first rigorously increased sequence
            while(ind<sz-1 && prices[ind+1]<=prices[ind]) ind++;
            minPrice = prices[ind];
            //find the first item of the first rigorously decreased sequence
            while(ind<sz-1 && prices[ind+1]>=prices[ind]) ind++;
            maxPrice = prices[ind];
            totalProfit += (maxPrice-minPrice);
            ind++;
        }
        return totalProfit;
    }
};
