class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mymap;
        for (int i=0; i<nums.size(); i++)
        {
            if (mymap.count(nums[i]))
                mymap[nums[i]]++;
            else
                mymap[nums[i]] = 1;
        }
        int maxVal = INT_MIN, res = -1;
        for (auto it: mymap)
        {
            if (it.second>maxVal)
            {
                maxVal = it.second;
                res = it.first;
            }
        }
        return res;
    }
};
