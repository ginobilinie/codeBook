class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty())
            return;
        int sz = nums.size();
        int zeros=0, ones=0, twos=0;
        for (int i=0; i<sz; i++)
        {
            if (nums[i]==0)
                zeros++;
            else if (nums[i]==1)
                ones++;
            else if (nums[i]==2)
                twos++;
        }
        int p=0;
        while(p<zeros)
        {
            nums[p++] = 0; 
        }
        while(p<zeros+ones)
        {
            nums[p++] = 1;
        }
        while (p<sz)
        {
            nums[p++] = 2;
        }
            
    }
};
