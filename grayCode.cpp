class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = { 0 };
        for (int f = 1; n > 0; f <<= 1, --n)
            for (int j = f - 1; j >= 0; --j) 
                res.push_back(res[j] + f);
        return res;
    }
};
