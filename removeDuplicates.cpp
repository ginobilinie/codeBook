class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        int tmp = nums[0];
        for (int i = 1; i<nums.size(); i++)
        {
            if (tmp==nums[i])
            {
                nums.erase(nums.begin()+i);
                i--;
            }
            else
                tmp = nums[i];
        }
        return nums.size();
    }
};
