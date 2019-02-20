class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //scan from left to right, and then scan from right to left
        //scan from left to right, prod[i] = prod[i-1]*nums[i-1]//avoid by nums[i]
        //scan from right to left, prod[i] = prod[i]*ac, where ac *=nums[i+1]
        vector<int> prod(nums.size(),1);
        for (int i=1; i<nums.size(); i++)
        {
            prod[i] = prod[i-1]*nums[i-1];
        }
        int ac = 1;
        for (int i=nums.size()-2; i>=0; i--)
        {
            ac *= nums[i+1];
            prod[i] *= ac;
        }
        return prod;
    }
};
