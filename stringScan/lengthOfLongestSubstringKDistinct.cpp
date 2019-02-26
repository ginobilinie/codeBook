class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.length()<=k)
            return s.length();
        int left = 0, maxLen = 0;
        unordered_map<char,int> mymap;
        for (int i=0; i<s.length(); i++)
        {
            mymap[s[i]]++;
            while(mymap.size()>k)
            {
                mymap[s[left]]--;
                if (mymap[s[left]]==0)
                    mymap.erase(s[left]);
                left++;
            }
            if (i-left+1>maxLen)
                maxLen = i-left+1;
        }
        return maxLen;
    }
};
