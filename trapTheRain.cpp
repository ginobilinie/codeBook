class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        int res = 0, currHeight=0;
        // for (int i=0; i<sz; i++)
        // {
        //     if (currHeight<height[i])
        //         currHeight = height[i];
        //     else
        //         continue;
        //     int possSum = 0,k; 
        //     for (k=sz-1; k>i; k--)
        //     {
        //         if (height[k]>currHeight)
        //             break;
        //     }       
        //     if (k==i)
        // }
        
        int firstPosGreaterThanCurrMin;//first position larger than the current min
        int lastPosGreaterThanCurrMin;//last position larger than the current min
        int currMin, minVal=INT_MAX, maxVal=-1;
        for (int i=0; i<sz; i++)
        {
            if (height[i]>maxVal)
                maxVal = height[i];
            if (height[i]<minVal)
                minVal = height[i];
        }
        for (currMin=minVal; currMin<=maxVal; currMin++)
        {
            firstPosGreaterThanCurrMin = -1;
            lastPosGreaterThanCurrMin = -1;
            for (int i=0; i<sz; i++)
                if (height[i]>currMin)
                {
                    if (firstPosGreaterThanCurrMin==-1)
                        firstPosGreaterThanCurrMin = i;
                    lastPosGreaterThanCurrMin = i;
                }
            if (firstPosGreaterThanCurrMin==-1)
                continue;
            for (int k=firstPosGreaterThanCurrMin; k<lastPosGreaterThanCurrMin; k++)
            {
                if (height[k]==currMin)
                {
                    height[k]++;
                    res++;  
                }

            }
        }
        return res;
    }
};
