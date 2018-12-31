class Solution {
public:
   double myPow(double x, long long n) {
        if (abs(x)<1e-7) return 0;
        long long k = n;
        if (k<0)
            k = -k;
        
        double res;
        if (n<0)
        {
            res = biPow(1/x,k);
        }
        else
        {
            res = biPow(x, k);
        }
        return res;
    }
    
    //n: positive integer
    double biPow(double x, long long n)
    {
        if (n==0)
            return 1;
        if (n==1)
            return x;
        long long left = n/2;
        long long right = n - left;
        double lval, rval;
        if (left==right)
        {
            lval = biPow(x,left);
            rval = lval;
        }
        else
        {
            lval = biPow(x,left);
            rval = lval*x;
        }
        return lval*rval;
    }
};
