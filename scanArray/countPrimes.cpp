class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> isPrime(n+1,1);
        int tt = sqrt(n);
        for (int i=2; i<=tt; i++)
        {
            if (isPrime[i])
            {
                // cout<<i<<" ";
                cnt++;
                for (int j=i; j*i<=n; j++)
                {
                    isPrime[j*i] = 0;
                }
            }
        }
        for (int i= tt+1; i<n; i++)
            if (isPrime[i])
                cnt++;
        return cnt;
    }
};
