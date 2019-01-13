class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
       map<int,bool> mymap;
        for (int i=0; i<nums.size(); i++)
        {
            mymap[nums[i]] = 1; 
        }
        map<int,bool>::iterator it = mymap.begin();
        
        int prev = it->first;
        it++;
        int maxLen = 1;
        int currMaxLen = 1;
        for (; it!=mymap.end(); it++)
        {
            
            
            while (it!=mymap.end() && prev+1==it->first)
            {
                prev = it->first;
                currMaxLen++;
                it++;
            }
            if (currMaxLen>maxLen)
                maxLen = currMaxLen;
            currMaxLen = 1;
            if (it!=mymap.end())
                prev = it->first;
            else
                break;
        }
        return maxLen;
    }
};
