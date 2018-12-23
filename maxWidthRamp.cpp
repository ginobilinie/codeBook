class Solution {
public:
    struct item
    {
        int val;
        int ind;
    } myItem[50000];
    
    static bool compareInterval(struct item i1, struct item i2) 
    { 
        if (i1.val==i2.val)
            return i1.ind<i2.ind;
        return (i1.val < i2.val); 
    } 
  
    int maxWidthRamp(vector<int>& A) {
        int maxLen = 0;
        int len = A.size();
        // struct item items = new struct item(len);
        // for (int i=0; i<len; i++)
        //     for (int j=i+1; j<len; j++)
        //     {
        //         if (A[j]>=A[i] && j-i>maxLen)
        //             maxLen = j-i;
        //     }
        for (int i=0; i<len; i++)
        {
            myItem[i].val = A[i];
            myItem[i].ind = i;
        }
        sort(myItem,myItem+len, compareInterval);
        int l=0, r=len-1;
        int maxInd=0, minInd=50000;
        // while (l<r)
        // {
        //     if (myItem[l].ind<minInd)
        //         minInd = myItem[l].ind;
        //     else
        //         l++;
        //     if (myItem[r].ind>maxInd)
        //         maxInd = myItem[r].ind;
        //     else
        //         r--;
        //     if (myItem[l].ind<minInd && myItem[r].ind>maxInd)
        //         r--;
        // }
        for (int i=0; i<len; i++)
        {
            if (myItem[i].ind<minInd)
                minInd = myItem[i].ind;
            if (myItem[i].ind-minInd>maxLen)
                maxLen = myItem[i].ind-minInd;
        }
        return maxLen;
    }
};
