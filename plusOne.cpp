class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        if (digits.empty())
            return res;
        int sz = digits.size();
        long long val = 0;
        digits[sz-1] =  digits[sz-1] + 1;
        int degree = 0;
        for (int i= sz-1; i>-1; i--)
        {
            digits[i] = digits[i] + degree;
            res.push_back(digits[i]%10);
            degree = digits[i]/10;
        }
        if (degree>0)
            res.push_back(degree);
        reverse(res.begin(), res.end());
        return res;
    }
};
