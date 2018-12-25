class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        double loc = -1;
        int res = biSearch(nums, target,loc);
        if (res!=-1)
            return res;
        res = ceil(loc);
        if (nums[res]<target)
            res = res+1;
        return res;
    }
    
    int biSearch(vector<int> & nums, int target, double& loc)
    {
        int ind = -1;
        int left=0, right = nums.size()-1, mid = (left+right)/2;
        while (left<right)
        {
            mid = (left+right)/2;
            if (nums[mid]==target)
            {
                ind = mid;
                break;
            }
            else if (nums[mid]<target)
                left = mid + 1;
            else
                right = mid -1;
        }
        loc = (left+right)/2.0;
        return ind;
    }
};
