class Solution {
public:
    int divide(int dividend, int divisor) {
        long long res = 0;
        if (dividend==0)
            res = 0;
        else if (divisor==1)
            res = dividend;
        else if (divisor==-1)
            res = 0 - (long long)dividend;
        else
        {
            bool flag = true;//both + or both -
            if (divisor<0)
            {
                flag = false;
                divisor = 0 - divisor;
            }
            if (dividend<0)
            {
                if (flag)
                    flag = false;
                else
                    flag = true;    
                dividend = 0 - dividend;
            }


            while(dividend-divisor>=0)
            {
                dividend -= divisor;
                res++;

            }

            if (flag)
                res = res;
            else
                res = 0-res;
        }
        if (res>INT_MAX)
            res = INT_MAX;
        return res;
    }
};
