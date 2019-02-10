class Solution {
public:
    int subarraysWithKDistinct_bruteforce_pass(vector<int>& A, int K) {
        int res = 0;
         // unordered_set<int> myset;
        int distcnt = 0;
        bool* used = new bool[A.size() + 1]; //Given 1 <= A.length <= 20000 and 1 <= A[i] <= A.length

        for (int i=0; i<A.size(); i++)
        {
            memset(used,0,(A.size()+1)*sizeof(bool));

            distcnt = 0;
            // vector<bool> used(A.size()+1,0);
            // myset.insert(A[i]);
            used[A[i]] = 1;
            distcnt ++;
            // if (myset.size()==K)
            //     res++;
            if (distcnt==K)
                res++;
            for (int j=i+1; j<A.size(); j++)
            {
                // myset.insert(A[j]);
                if (!used[A[j]])
                {
                    used[A[j]] = 1;
                    distcnt++;
                }
                if (distcnt==K)
                    res++;
                else if (distcnt>K)
                    break;
                // if (myset.size()==K)
                //     res++;
                // if (myset.size()>K)
                //     break;
            }   
            // myset.clear();
        }
        return res;

    }
};
