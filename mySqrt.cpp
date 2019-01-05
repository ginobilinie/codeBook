class Solution {
public:
    #define eps 1e-1
    int mySqrt(int x) {
        if (x==0)
            return 0;
        int numOfDigits = 0, t = x;
        while (t)
        {
            if (t/10)
                numOfDigits++;
            t = t/10;
        }
        int num = numOfDigits/2+1;
        int guess = 0;
        while (num--)
        {
            guess = guess*10 + 5;
        }
        //guess is the guess start point
        //then we use newton iteration methods: f(a)= a^2 - x
        double val = guess;//val is a
        double fx, dfx;
        double diff = guess, tmp;
        while (abs(diff)>eps)
        {
            fx = val*val - x;
            dfx = 2*val;
            tmp = val;
            val -= 1.0*fx/dfx;
            diff = tmp - val;
        }
        int res = floor(val);
        return res;
    }
};
