class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.length();
        int ind = -1;
        for (int i=0; i< haystack.length(); i++)
        {
            if (needle==haystack.substr(i,len))
            {
                ind = i;
                break;
            }
        }
        if (haystack==""&& needle=="")
            ind = 0;
        return ind;
        
    }
};
