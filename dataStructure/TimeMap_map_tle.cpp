class TimeMap {
public:
    struct cmp
    {
      bool operator()(int p1, int p2)
      {
          return p1<p2;
      }
    };
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (mymap.count(key))
        {
            auto smap = mymap[key];
            smap[ -1*timestamp] = value;
            mymap[key] =smap;
        }
        else
        {
            map<int,string> smap;
            smap[ -1*timestamp] = value;
            mymap[key] = smap;
        }
    }
    
    string get(string key, int timestamp) {
           if (mymap.count(key))
           {
               auto smap = mymap[key];
               auto it = smap.lower_bound( -1*timestamp);
               if (it==smap.end())
                   return "";
               return it->second;
           }
            else
            {
                return "";
            }
    }
    private:
    //unordered_map<key,pq<pair<value,time>>>
    unordered_map<string,map<int,string>> mymap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
