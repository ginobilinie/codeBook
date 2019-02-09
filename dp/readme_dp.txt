 1. mincostTickets.cpp: a typical dp: dp[n] vs. dp[n-1], just consider how to place the n-th element there are three choices: 
 buy a 1-day pass, buy a 7-day pass (in this case, we should consider dp[n-7]), and buy a 30-day pass (in this case, we should consider dp[n-30]).
Thus, if the sub-system (n-1) is optimal, then if we place a best choice for (n), we can
have a perfect system (n), so we can use dp
tranfer equation: dp[n] = min(dp[n-1]+cost[0], dp[n-7]+cost[1], dp[n-30]+cost[2])
