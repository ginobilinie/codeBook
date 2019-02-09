class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        /*
        a typical dp: dp[n] vs. dp[n-1], just consider how to place the n-th element
        there are three choices: buy a 1-day pass, buy a 7-day pass (in this case, we should 
        consider dp[n-7]), and buy a 30-day pass (in this case, we should consider dp[n-30]).
        Thus, if the sub-system (n-1) is optimal, then if we place a best choice for (n), we can
        have a perfect system (n), so we can use dp
        tranfer equation: dp[n] = min(dp[n-1]+cost[0], dp[n-7]+cost[1], dp[n-30]+cost[2])
        */
        //I'm not sure if days are sorted or not
        sort(days.begin(),days.end());
        int maxDay = days[days.size()-1];
        vector<int> dp(maxDay+1,0);
        
        int ind = 0;
        for (int day=1; day<maxDay+1; day++)
        {
            if (day==days[ind])
            {
                ind++;
                int daymin = dp[day-1]+costs[0];
                int weakmin = day>6?costs[1]+dp[day-7]:costs[1];
                int monthmin = day>29?costs[2] +dp[day-30]:costs[2];
                dp[day] = min(min(daymin,weakmin),monthmin);
            }
            else//not included
            {
                dp[day] = dp[day-1];
            }
        }
        return dp[maxDay];
    }
};
