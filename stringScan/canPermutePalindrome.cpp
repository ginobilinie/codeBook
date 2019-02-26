class Solution {
public:
    bool canPermutePalindrome(string s) {
        //to record the number of each char, if there are more than one char appears odd times, then false
        //we can use map to do it with O(n) time and O(n) extra space or we can use sort to do it with O(1) space and O(nlogn) time
        unordered_map<char,int> mymap;
        for (char c : s)
        {
            mymap[c]++;
        }
        int cnt = 0;
        for (auto it : mymap)
        {
            if (it.second%2)
                cnt++;
        }
        if (cnt>1)
            return false;
        return true;
    }
};
