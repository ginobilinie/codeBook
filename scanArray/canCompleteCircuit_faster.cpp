class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //this version provides a O(n^2) algorithm
        if (gas.empty())
            return -1;
        int len = gas.size();
        int res = -1;
        
        for (int i=0; i<len; i++)
        {
            gas[i] -= cost[i];
        }
        
        //find the minimum cumulative
        int minInd = 0, minVal = gas[0];
        for (int i=1; i<len; i++)
        {
            gas[i] += gas[i-1];
            if (gas[i]<minVal)
            {
                minVal = gas[i];
                minInd = i;
            }
        }
        if (gas[len-1]>=0)//we can find such a route
            res = (minInd+1)%len;
        return res;
    }
};
