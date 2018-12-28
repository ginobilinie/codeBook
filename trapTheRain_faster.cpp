class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int sz = height.size();
        int maxVal=-1, ind4MaxVal;
        
        int res = 0;
        
        for (int i=0; i<sz; i++)
        {
            if (height[i]>maxVal)
            {
                maxVal = height[i];
                ind4MaxVal = i;
            }
        }
        
        int currP=0, nextP;
        while(currP<ind4MaxVal)
        {
            nextP = currP+1;
            while(nextP<=ind4MaxVal&&height[currP]>height[nextP])
            {
                res += height[currP] - height[nextP];
                nextP++;
            }
            currP = nextP;
        }
        
        currP=sz-1;
        while(currP>ind4MaxVal)
        {
            nextP = currP-1;
            while(nextP>=ind4MaxVal&&height[currP]>height[nextP])
            {
                res += height[currP] - height[nextP];
                nextP--;
            }
            currP = nextP;
        }
        return res;
    }
};
