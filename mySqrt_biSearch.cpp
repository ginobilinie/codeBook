class Solution {
public:
    #define eps 1e-1
    int mySqrt(int x) {
        if (x==0||x==1)
            return x;
        int l=0, r=x, mid, res;
        while(l<=r)
        {
            mid = (l+r)/2;
            if (mid==x/mid)
            {
                res = mid;
                break;
            }
            else if (mid<x/mid)//right side
            {
                l = mid+1;
            }
            else
                r = mid -1;
        }
        res = (l+r)/2;
        return res;
    }
};
