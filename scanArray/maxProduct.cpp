class Solution {
public:
    // #define maxBi(x,y) x<y?y:x
    // #define maxVal(x,y,z) maxBi(maxBi(x,y),z)
    // #define minBi(x,y) x<y?x:y
    // #define minVal(x,y,z) minBi(minBi(x,y),z)
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int hisMax = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            // cout<<currMin<<" ";
            int prevMax = currMax;
            currMax = max(max(currMax*nums[i],currMin*nums[i]),nums[i]);
            currMin = min(min(prevMax*nums[i],currMin*nums[i]),nums[i]);
            hisMax = max(currMax,hisMax);
        }
        return hisMax;
    }
};
