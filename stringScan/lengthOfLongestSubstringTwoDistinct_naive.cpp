class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.length()<=2)
            return s.length();
        int maxLen = 0;
        for (int i=0; i<s.length(); i++)
        {
            unordered_map<char,int> mymap;
            mymap[s[i]]++;
            for (int j=i+1; j<s.length(); j++)
            {
                mymap[s[j]]++;
                if (mymap.size()>2)
                    break;
                else
                {
                    if (maxLen<j-i+1)
                        maxLen = j-i+1;
                }
            }            
        }
        return maxLen;
    }
};
