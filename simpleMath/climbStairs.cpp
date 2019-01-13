class Solution {
public:
    int climbStairs(int n) {
    if (n==0)
        return 1;
      if (n==1)
          return 1;
    if (n==2)
        return 2;
    int res = 0, v1 = 1, v2 = 2;
    for (int i=3; i<=n; i++)
    {
        res = v1 + v2;
        v1 = v2;
        v2 = res;
    }
    return res;
    }
};
