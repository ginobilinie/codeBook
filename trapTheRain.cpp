//tle v1
class Solution {

public:
    int trap(vector<int>& height) {
        int sz = height.size();
        int res = 0, currHeight=0;

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

//tle v2
class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        if (height.empty())
            return 0;
        int res = 0, currHeight=0;
        set<int> myset;
        
        vector<int> tmp = height;
        sort(tmp.begin(),tmp.end());
        
        for (int i=0; i<sz; i++)
            myset.insert(tmp[i]);// the set is sorted from smaller valut to large value
        
        
        int firstPosGreaterThanCurrMin;//first position larger than the current min
        int lastPosGreaterThanCurrMin;//last position larger than the current min
        int currMin, nextMin, minVal=INT_MAX, maxVal=-1;

        set<int>:: iterator it, tmpIt;
        for (it=myset.begin(); it!=myset.end();)
        {
            currMin = *it;
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
            it++;
            if (it!=myset.end())
            {
                nextMin = *it;
                for (int k=firstPosGreaterThanCurrMin; k<lastPosGreaterThanCurrMin; k++)
                {
                    if (height[k]==currMin)
                    {

                        height[k] = nextMin;
                        res = res + nextMin - currMin;  
                    }

                }
                currMin = nextMin;
            }
        }
        return res;
    }
};


//not finihsed version.
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
