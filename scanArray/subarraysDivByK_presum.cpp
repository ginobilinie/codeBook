class Solution {
public:
    // int res = 0;
    int subarraysDivByK(vector<int>& A, int K) {
        //sameMod vector records the number of the prefix sums with same remainder against modouls K.
        //Briefly speaking, we use sameMode to record the number of r = (A[0]+A[1]+...A[i])%K, and we use sameMod[r] counts it
        //that's because if, two sameMod[r], then (sameMod1-sameMod2)%K==0, so we can add 1, 
        //if a remainder r comes (assume we have previously x such remainder r), then we can use this new r to match the previous
        //x remainders r, so we should add x to the final solution.
        vector<int> sameMod(K+1,0);
        int currSum = 0;
        int res = 0;
        for (int i=0; i<A.size(); i++)
        {
            currSum += A[i];
            if (currSum%K==0)
                res++;
            int r = currSum%K;
            if (r<0)
                r = r+K;
            res += sameMod[r];
            sameMod[r]++;
        }
        return res;
    }
    
};
