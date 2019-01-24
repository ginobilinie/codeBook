class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        /*
        using unordered_map<string,int> with sliding window to scan the string
        */
        if (s==""||s.length()<10)
            return {};
        unordered_map<string,int> mymap;
        for (int i=0; i<s.length()+1-10; i++)
        {
            string str = s.substr(i,10);
            if (mymap.count(str))
                mymap[str]++;
            else
                mymap[str] = 1;
        }
        vector<string> res;
        for (auto it : mymap)
        {
            if (it.second>1)
                res.push_back(it.first);
        }
        return res;
    }
};
