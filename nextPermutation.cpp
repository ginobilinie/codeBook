class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int i, j, tmp;
        int lInd=-1, rInd=INT_MAX;
        for (i=len-1; i>0; i--)
        {
            for (j=i-1; j>lInd; j--)
            {
                if (nums[i]>nums[j])
                {
                    lInd = j;
                    rInd = i;
                }
            }

        }
        if (lInd!=-1)
        {
            tmp = nums[lInd];
            nums[lInd] = nums[rInd];
            nums[rInd] = tmp;
            sort(nums.begin()+lInd+1,nums.end());   
        }
        else//we reverse the nums
        {
            int l=0, r=len-1;
            while (l<r)
            {
                tmp = nums[l];
                nums[l] = nums[r];
                nums[r] = tmp;
                l++;
                r--;
            }
        }
    }
};
