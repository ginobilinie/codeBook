class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return true;
        int currMaxReachInd = 0;
        // vector<int> maxReachVec;
        int sz = nums.size();
        if (sz==1)
            return true;
        // for (int i=0; i<sz; i++)
        //     maxReachVec.push(0);
        bool res = false;
        for (int i=0; i<sz-1; i++)
        {
            if (currMaxReachInd<i)
            {
                break;
            }
            int tmp = i + nums[i];
            if (currMaxReachInd<tmp)
                currMaxReachInd = tmp;
            if (currMaxReachInd>=sz-1)
            {
                res = true;
                break;
            }
        }
        return res;
    }
    
};
