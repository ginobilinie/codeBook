class Solution {
public:
    int numTrees(int n) {
        //f(n) = sigma_k_1ton(f(n-k)*f(k-1))
        //int res = func(n);
        
        vector<int> vec(n+1,0);
        vec[0] = 1;
        vec[1] = 1;
        for (int i=2; i<=n; i++)
        {
            for (int k=1; k<=i; k++)
            {
                vec[i] += vec[i-k]*vec[k-1];
            }
        }
        
        return vec[n];
    }
    
    // int func(int n)
    // {
    //     if (n==0||n==1)
    //         return 1;
    //     int res = 0;
    //     for (int i=1; i<=n; i++)
    //     {
    //         res += func(n-i)*func(i-1);
    //     }
    //     return res;
    // }
};
