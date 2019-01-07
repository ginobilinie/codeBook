class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool res = biSearch(nums, target);
        return res;
    }
    
    bool biSearch(vector<int>& nums, int target)
    {
        int l=0, r = nums.size()-1, mid;
        
        bool res = 0;
        while (l<=r)
        {
            mid = (l+r)/2;
            if (nums[mid]==target)
            {
                res = 1;
                break;
            }
            else if (nums[mid]<nums[r])//right side is ordered
            {
                if (target>=nums[mid] && target<=nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else //left side is ordered
            {
                if (nums[l]<=target&&target<=nums[mid])
                {
                    r = mid -1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return res;
    }
};
