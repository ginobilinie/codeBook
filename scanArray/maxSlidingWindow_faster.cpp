class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty())
            return {};
        int maxVal = INT_MIN, maxInd = -1;
        vector<int> res;
        for (int j=0; j<k; j++)
        {
            if (nums[j]>maxVal)
            {
                maxVal = nums[j];
                maxInd = j;                        
            }
        }
        res.push_back(maxVal);
        for (int i=1; i<nums.size()-k+1; i++)
        {
            
            if (maxInd==i-1)//we need to rescan
            {
                maxVal = INT_MIN;
                for (int j=i; j<i+k; j++)
                if (nums[j]>maxVal)
                {
                      maxVal = nums[j];                
                      maxInd = j;                  
                }
            }
            else
            {
                if (maxVal<=nums[i+k-1])
                {
                    maxVal = nums[i+k-1];       
                    maxInd = i+k-1;
                }
            }
        
            res.push_back(maxVal);
        }
        return res;
    }
};
