class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size()<2)
            return 0;
        sort(nums.begin(),nums.end());
        int maxD = 0;
        for (int i=1; i<nums.size(); i++)
        {
            if (maxD<nums[i]-nums[i-1])
                maxD = nums[i]-nums[i-1];
        }
        return maxD;
    }
};
