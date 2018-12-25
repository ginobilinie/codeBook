class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = biSearchLeft(nums, target);
        int right = biSearchRight(nums, target);
        vector<int> res;
        res.push_back(left);
        res.push_back(right);
        return res;
    }
    
    int biSearchLeft(vector<int>& nums, int target)
    {
        int res = -1;
        int l=0, r=nums.size()-1,mid;
        while(l<=r)
        {
            mid = (l+r)/2;
            if (nums[mid]==target)
            {
                res = mid;
                r = mid - 1;
            }
            else if (nums[mid]<target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return res;
    }
    
    int biSearchRight(vector<int>& nums, int target)
    {
        int res = -1;
        int l=0, r=nums.size()-1,mid;
        while(l<=r)
        {
            mid = (l+r)/2;
            if (nums[mid]==target)
            {
                res = mid;
                l = mid + 1;
            }
            else if (nums[mid]<target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return res;
    }
};
