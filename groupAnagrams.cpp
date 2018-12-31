class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mymap;
        int sz = strs.size();
        vector<string> tvec;
        vector<vector<string>> resvec;
        for (int i=0; i<sz; i++)
        {
            string str = strs[i];
            sort(str.begin(),str.end());
            if (mymap.count(str))
            {
                mymap[str].push_back(strs[i]);
            }
            else
            {
                tvec.clear();
                tvec.push_back(strs[i]);
                mymap[str] = tvec;
            }
        }
        for(map<string,vector<string>>::iterator it = mymap.begin(); it != mymap.end(); ++it ) 
            resvec.push_back( it->second);
        return resvec;
    
    }
};
