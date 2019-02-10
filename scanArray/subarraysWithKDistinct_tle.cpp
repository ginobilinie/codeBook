class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int res = 0;
        for (int i=0; i<A.size(); i++)
        {
            unordered_set<int> myset;
            myset.insert(A[i]);
            if (myset.size()==K)
                res++;
            for (int j=i+1; j<A.size(); j++)
            {
                myset.insert(A[j]);
                if (myset.size()==K)
                    res++;
                if (myset.size()>K)
                    break;
            }            
        }
        return res;

    }
};
