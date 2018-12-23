class Solution {
public:
int divide(long long dividend, long long divisor) {
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
            dividend = 0 - (long long)dividend;
        }
		if (dividend<divisor)
			res = 0;
		else
		{

//             while(dividend-divisor>=0)
//             {
//                 dividend -= divisor;
//                 res++;
//             }
			long long tmp = divisor;
			int numberOfLeftOp = 0;
			while(true)//find the largest number of left ops 
			{
				tmp <<= 1;  
				numberOfLeftOp++;
				if (dividend<tmp)
				{
					tmp>>=1;
					numberOfLeftOp--;
					break;
				}
			}
			while(numberOfLeftOp>0)
			{
				if (dividend>=tmp)
				{
					dividend -= tmp;
					res += 2<<(numberOfLeftOp-1);
				}
				numberOfLeftOp--;
				tmp >>= 1;
			}
			if (dividend>=tmp)
				res+=1;

			if (flag)
				res = res;
			else
				res = 0-res;
		}
    }
    if (res>INT_MAX)
        res = INT_MAX;
    return res;
}
};
