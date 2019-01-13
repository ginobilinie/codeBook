class Solution {
public:
    // int res = 0;
    int subarraysDivByK(vector<int>& A, int K) {
        //sort(A.begin(),A.end());
        // for (int i=0; i<A.size(); i++)
        // {
        //     dfs(A,i,A[i],K);
        // }
        int res = 0;
        int currSum = 0;
        for (int i=0; i<A.size(); i++)
        {
            currSum = A[i];
            if (currSum%K==0)
                res++;
            for (int j=i+1; j<A.size(); j++)
            {
                currSum += A[j];
                if (currSum%K==0)
                    res++;
            }
        }
        return res;
    }
    
    // void dfs(vector<int>& A, int currInd, int currSum, int K)
    // {
    //     if (currSum%K==0)
    //     {
    //         res++;
    //         //return;
    //     }
    //     for (int i=currInd+1; i<A.size(); i++)
    //     {
    //         // currVec.push_back(A[i]);
    //         dfs(A, i, currSum+A[i], K);
    //         while (i+1<A.size()&&A[i]==A[i+1]) i++;
    //     }
    // }
};
