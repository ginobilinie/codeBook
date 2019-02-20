class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if (nums.empty()||nums[nums.size()-1]<lower||nums[0]>upper)
        {
            if (lower==upper)
                res.push_back(to_string(lower));
            else
                res.push_back(to_string(lower)+"->"+to_string(upper));
            return res;
        }
        int ind = 0;
        long long left = lower;
        for (long long num : nums)
        {
            if (num<left)
                continue;
            else if (num==left)
            {
                left = left+1;
                if (left>upper)
                    break;
            }
            else//num>lower
            {
                int right = num - 1;
                if (num>upper)
                    right = upper;
                if (left==right)
                {
                    res.push_back(to_string(left));
                }
                else
                    res.push_back(to_string(left)+"->"+to_string(right));
                // if (num==2147483647)
                //     break;
                // if (num==upper)
                // {
                //     left = num;
                //      break;   
                // }
                left = num+1;
                if (left>upper)
                    break;
            }
            // if (num>upper)
            // {
            //     res.push_back(to_string(lower),"->",to_string(upper));
            // }
            // else if (num==upper)
            // {
            //     res.push_back(to_string(lower),"->",to_string(upper-1));
            // }
        }
        if (left==upper)
            res.push_back(to_string(left));
        else if (left<upper)
            res.push_back(to_string(left)+"->"+to_string(upper));
                
        return res;
    }
};
