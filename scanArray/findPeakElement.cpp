class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size()==1)
            return 0;
        
        int sz = nums.size();
        if (nums[0]>nums[1])
            return 0;
        if (nums[sz-1]>nums[sz-2])
            return sz-1;
        int res = 0;
        for (int i=1; i<sz-1; i++)
        {
            if (nums[i]>nums[i-1]&&nums[i]>nums[i+1])
            {
                res = i;
                break;
            }
                // return i;
        }
        return res;
    }
};
