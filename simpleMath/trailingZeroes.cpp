class Solution {
public:
    int trailingZeroes(int n) {
        //first compute the values only containing one 5
        //then compute the values containing two 5
        //...
        int res = 0;
        while(n)
        {
            res += n/5;
            n /= 5;
        }
        return res;
    }
};
