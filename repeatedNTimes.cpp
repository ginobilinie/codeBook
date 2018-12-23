class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        sort(A.begin(),A.end());
        int res = -1;
        for (int i=0;i<A.size()/2+1; i++)
        {
            if (A[i]==A[i+1])
            {
                res = A[i];
                break;
            }
        }
        return res;
    }
};
