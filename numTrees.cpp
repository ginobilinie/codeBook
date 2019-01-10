class Solution {
public:
    int numTrees(int n) {
        //f(n) = sigma_k_1ton(f(n-k)*f(k-1))
        int res = func(n);
        return res;
    }
    
    int func(int n)
    {
        if (n==0||n==1)
            return 1;
        int res = 0;
        for (int i=1; i<=n; i++)
        {
            res += func(n-i)*func(i-1);
        }
        return res;
    }
};
