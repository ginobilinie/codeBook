class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
       unordered_map<int,bool> mymap;
        for (int i=0; i<nums.size(); i++)
        {
            mymap[nums[i]] = 1; 
        }
        unordered_map<int,bool>::iterator it = mymap.begin();
        
        int curr = it->first;
        // it++;
        mymap.erase(curr);
        int maxLen = 1;
        int currMaxLen = 1;
        while (!mymap.empty())
        {
            int tmp = curr;
            //upper side
            while (!mymap.empty()&&mymap.count(tmp+1))
            {
                currMaxLen++;
                tmp = tmp+1;
                mymap.erase(tmp);
            }
            //lower side
            tmp = curr;
            while(!mymap.empty()&&mymap.count(tmp-1))
            {
                currMaxLen++;
                tmp = tmp -1;
                mymap.erase(tmp);
            }
            if (currMaxLen>maxLen)
                maxLen = currMaxLen;
            if (!mymap.empty())
            {
                it = mymap.begin();
                curr = it->first;
                mymap.erase(curr);
                currMaxLen = 1;                
            }
        }
        return maxLen;
    }
};
