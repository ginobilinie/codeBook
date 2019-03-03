class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0, zero = 0, left = 0;
        for (int right = 0; right < A.size(); right++) {
            if (A[right] == 0) 
                zero++;
            while (zero > K) {
                if (A[left] == 0) 
                {
                    zero--;
        
                }
                left++;
            }
            // cout<<left<<":"<<right<<":"<<zero<<endl;
            res = max(res, right - left + 1);
        }
        return res;
    }
};
