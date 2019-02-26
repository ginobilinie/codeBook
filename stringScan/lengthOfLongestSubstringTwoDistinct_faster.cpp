class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.length()<=2)
            return s.length();
        int maxLen = 0, left = 0;
        unordered_map<char,int> mymap;
        for (int i=0; i<s.length(); i++)
        {
            mymap[s[i]]++;
            while (mymap.size()>2)
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
