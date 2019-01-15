class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mymap;
        for (int i=0; i<nums.size(); i++)
        {
            if (mymap.count(nums[i]))
                mymap[nums[i]]++;
            else
                mymap[nums[i]] = 1;
        }
        int res = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (mymap[nums[i]]==1)
            {
                res = nums[i];
                break;
            }
                
        }
        return res;
    }
};
