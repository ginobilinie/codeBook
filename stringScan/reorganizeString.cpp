class Solution {
public:
    struct cmp
    {
      bool operator() (const pair<int,char> &a, const pair<int,char>& b) const
      {
          if (a.first==b.first)
              return a.second<b.second;
          return a.first>b.first;
      }
    };
    string reorganizeString(string S) {
        unordered_map<char,int> mymap;
        int maxLen = 0;
        for (auto c : S)
        {
            mymap[c]++;
            if (mymap[c]>maxLen)
                maxLen = mymap[c];
        }
        int len = S.length();
        if (maxLen>(len+1)/2)
            return "";
        string res = "";
        set<pair<int,char>,cmp> myset;
        for (auto it : mymap)
        {
            myset.insert({it.second,it.first});
        }
        // cout<<"l30: "<<myset.size()<<endl;
        while (!myset.empty()&&myset.size()>1)
        {
            auto it1 = myset.begin();
            auto p1 = *it1;//this step is necessary
            myset.erase(it1);//it will destroy it1, too
            auto it2 = myset.begin();
            auto p2 = *it2;
            myset.erase(it2);
            
            res += p1.second;
            res += p2.second;
            if (p1.first-1>0)
                myset.insert({p1.first-1,p1.second});
            if (p2.first-1>0)
                myset.insert({p2.first-1,p2.second});
        }
        if (!myset.empty())
            res += myset.begin()->second;
        return res;
    }
};
