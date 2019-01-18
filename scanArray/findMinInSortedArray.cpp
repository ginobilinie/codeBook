class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        if (nums.empty())
            return 0;
        int res = 0;
        res = biSearch(nums);
        return res;
    }
    
    int biSearch(vector<int>& nums)
    {
        int l=0, r=nums.size()-1, mid=(l+r)/2;
        while(l<=r)
        {
            mid = (l+r)/2;
            if (l==r)
                break;
            //cout<<mid<<" ";
            if (nums[l]<nums[r])//the current sequence are ordered
            {
                mid = l;
                break;
            }
            else if (nums[l]<=nums[mid])//left side is ordered
            {
                //= menas l==r cases
                l = mid+1;
            }
            else if (nums[mid]<nums[r])//right side is ordered
            {
                r = mid;
            }
        }
        // mid = (l+r)/2;
        return nums[mid];
    }
};
