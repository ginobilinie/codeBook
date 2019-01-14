class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //this version provides a O(n^2) algorithm
        if (gas.empty())
            return -1;
        int len = gas.size();
        int res = -1;
        for (int i=0; i<len; i++)//starting point
        {
            int currGasSum = 0, currCostSum = 0;
            int j = i;
            for (; j<i+len; j++)
            {
                int ind = j%len;
                currGasSum += gas[ind];
                currCostSum += cost[ind];
                if (currGasSum<currCostSum)
                {
                    break;
                }
            }
            if (currGasSum>=currCostSum)
            {
                res = i;
                break;
            }
            if (j==i+len&&currCostSum>currGasSum)
            {
                res = -1;
                break;
            }
        }
        return res;
    }
};
