class Solution {
public:
    struct cmp
    {
      bool operator()(const int& a, const int& b) const
      {
          return a>b;
      }
    };
    string frequencySort(string s) {
        unordered_map<char,int> dict;
        for (auto c : s)
            dict[c]++;
        map<int,vector<char>,cmp> mymap;
        for (auto it : dict)
        {
            if(mymap.count(it.second))
            {
                mymap[it.second].push_back(it.first);
            }
            else
            {
                vector<char> myvec;
                myvec.push_back(it.first);
                mymap[it.second] = myvec;
            }
        }
        string res = "";
        for (auto it : mymap)
        {
            vector<char> vec = it.second;
            for (auto c : vec)
                for (int i=0; i<it.first; i++)
                    res += c;
        }
        return res;
    }
};
