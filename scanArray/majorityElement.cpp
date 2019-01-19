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

//only one for loop pass
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mymap;
        int maxVal = INT_MIN, res = -1;
        for (int i=0; i<nums.size(); i++)
        {
            if (mymap.count(nums[i]))
                mymap[nums[i]]++;
            else
                mymap[nums[i]] = 1;
            if (maxVal<mymap[nums[i]])
            {
                maxVal = mymap[nums[i]];
                res = nums[i];
            }
        }
        
        // for (auto it: mymap)
        // {
        //     if (it.second>maxVal)
        //     {
        //         maxVal = it.second;
        //         res = it.first;
        //     }
        // }
        return res;
    }
};
