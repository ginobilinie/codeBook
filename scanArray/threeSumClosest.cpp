class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int minMargin = INT_MAX;
        int res = target;
        for (int i=0; i<len; i++)
        {
            for (int j=i+1; j<len; j++)
            {
                for (int k=j+1; k<len; k++)
                {
                    int sum = nums[i]+nums[j]+nums[k];
                    if (abs(sum - target)<minMargin)
                    {
                        minMargin = abs(sum - target);
                        res = sum;     
                    }
                        
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int minMargin = INT_MAX;
        int res = target;
        sort(nums.begin(),nums.end());
        for (int i=0; i<len-2; i++)//fix a value
        {
            int left = i+1;
            int right = len-1;
            while(left<right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target)<minMargin)
                {
                    minMargin = abs(sum - target);
                    res = sum;     
                }
                if (sum<target)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};
