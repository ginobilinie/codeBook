class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int l = 0, r = nums.size()-1, mid = (l+r)/2;
        while(l<=r)
        {
            while (l<r&&nums[l]==nums[r]) r--;//this time, nums[l]!=nums[r]
            mid = (l+r)/2;
            if (l==r)
                break;
            if (nums[l]<nums[r])//the whole sequence between [l,r] is ordered
            {
                mid = l;
                break;
            }
            else if (nums[l]<nums[mid])//left side is ordered
            {
                l = mid + 1;
            }
            else if (nums[mid]<nums[r])//right side is ordered
            {
                r = mid;
            }
            else if (nums[l]==nums[mid])//nums[mid]>nums[r]
            {
                l = mid + 1;
            }
            else if (nums[mid]==nums[r])//nums[mid]<nums[l]
            {
                r = mid;
            }
        }
        return nums[mid];
    }
};
