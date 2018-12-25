class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = biSearch(nums,target);
        return res;
    }
    
 int biSearch(vector<int> &nums, int target)
    {
        int res = -1;
        int l=0, r=nums.size()-1, mid=(l+r)/2;
        while(l<=r)
        {
            mid = (l+r)/2;
            if (nums[mid]==target)
            {
                res = mid;
                break;
            }
            else if (target<nums[mid]&&nums[mid]>=nums[l])//we stay in left ordered half
            {
                if (target<nums[l])
                    l = mid+1;
                else
                    r = mid - 1;
            }
            else if (target<nums[mid]&&nums[mid]<nums[l])//left half is not ordered half
            {
				r = mid - 1;
            }
            else if (target>nums[mid] && nums[mid]<=nums[r])//we stay in the right ordered half
            {
                if (target>nums[r])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else // the right half is not ordered half
            {
				l = mid + 1;
            }
        }
        return res;
    }
};
