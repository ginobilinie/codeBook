class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int lastInd = nums.size()-1;
        int tmp = 0;
        while (lastInd>-1)
        {
            tmp = lastInd;
            while (tmp-1>-1&&nums[tmp]==nums[tmp-1])tmp--;
            while (lastInd-tmp>1)
            {
                nums.erase(nums.begin()+lastInd);
                lastInd--;
            }
            lastInd = tmp - 1;
        }
        return nums.size();
    }
};
