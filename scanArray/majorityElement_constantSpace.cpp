class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() < 2) return nums[0];
        // this method is very tricky: make full use of the definition: "more than n/2 times"
        int val = nums[0], cnt = 0;//val records the so-far most frequent value, 
        for (int i=0; i<nums.size(); i++)
        {
            if (val==nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;//other elements counterweigh one time of the current most frequent value, if cnt still >0, then means it is still the most frequent value
                if (cnt==0)//cnt==0, means it is not the so-far most frequent value
                {
                    val = nums[i];
                    cnt++;
                }
            }
        }
        return val;
    }
};
