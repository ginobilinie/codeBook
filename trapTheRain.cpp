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
                break;;
            if (firstPosGreaterThanCurrMin==lastPosGreaterThanCurrMin)
                break;
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



class Solution {
public:
    struct unit
    {
        int index;
        int val;
    };
    bool comp(struct unit& u1, struct unit& u2)
    {
        if (u1.val==u2.val)
            return u1.index<u2.index;
        return u1.val<u2.val;
    }
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int sz = height.size();
        vector<struct unit> myvec;
        struct unit myunit;
        for (int i=0; i<sz; i++)
        {
            myunit.index = i;
            myunit.val = height[i];
            myvec.push_back(myunit);
        }
        sort(myvec.begin(),myvec.end(),cmp);
        
        int currMinVal = myvec[0].val;
        int currMinInd = myvec[0].ind;
        int nextMinVal, nextMinInd;
        for (int i=1; i<sz; i++)
        {
            if (myvec[i].val==currMaxVal)
            {
                continue;
            }
            else
            {
                nextMaxVal = myvec[i].val;
            }
        }
        
        return res;
    }
};
