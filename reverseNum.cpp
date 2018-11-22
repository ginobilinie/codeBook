class Solution {
const int maxV = 2147483647;

const int minV = -2147483648;
    //we can also use INT_MAX or INT_MIN;
public:
    int reverse(int x) {
        int tmp = x>0?x:-1*x;
        long res = 0;
        while(tmp>0)
        {
            int tt = tmp%10;
            res = res*10 + tt; 
            tmp = tmp/10;
        }
        res = x>0?res:-1*res;
        if (res>maxV||res<minV)
            res = 0;
        return res;
    }
};
