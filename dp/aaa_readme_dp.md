 1. mincostTickets.cpp: a typical dp: dp[n] vs. dp[n-1], just consider how to place the n-th element there are three choices: 
 buy a 1-day pass, buy a 7-day pass (in this case, we should consider dp[n-7]), and buy a 30-day pass (in this case, we should consider dp[n-30]).
Thus, if the sub-system (n-1) is optimal, then if we place a best choice for (n), we can
have a perfect system (n), so we can use dp
tranfer equation: dp[n] = min(dp[n-1]+cost[0], dp[n-7]+cost[1], dp[n-30]+cost[2])

2. lenLongestFibSubseq.cpp: Use a 2-dim dp to solve this problem. dp[i][j] means the max length of F subsequence including a[i] and a[j], we just need to check if the tuple (a[i], a[j], a[i]-a[j]) can form a F sequence or not. The state convert equation is: suppose smallerVal = a[i] - a[j], and we have smallerVal < a[j], and smaller is in the suqenece (we can use a dict to do it), then we have: if dp[j][smallerInd] is not 0, dp[i][j] = max(dp[i][j], dp[j][smallerInd]+1), otherwise, dp[i][j] = 3, where smallerInd = dict[smallerVal].
