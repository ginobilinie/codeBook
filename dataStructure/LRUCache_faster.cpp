class LRUCache {
public:
    struct cmp
    {
      bool operator() (const pair<int,int>& p1, const pair<int,int>& p2) const  
      {
          return p1.second<p2.second;
      }
    };
    LRUCache(int capacity)
    {
        maxSZ = capacity;
        currPriority = 0;
    }
    
    int get(int key)
    {
        if (dict.count(key))
        {
            int val = mymap[{key,dict[key]}];
            mymap.erase({key,dict[key]});
            dict[key] = ++currPriority;
            mymap[{key,dict[key]}] = val;
            // cout<<"get "<<key<<" "<<dict[key]<<" "<<mymap[{key,dict[key]}]<<endl;
            return val;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value)
    {
        if (dict.count(key))
        {
            mymap.erase({key,dict[key]});
            dict.erase(key);
            dict[key] = ++currPriority;
            mymap[{key,dict[key]}] = value;
        }
        else
        {
              if (dict.size()>=maxSZ)
                {
                    auto it = mymap.begin();
                    int tkey = it->first.first;
                  //   cout<<tkey<<" "<<it->first.second<<" "<<it->second<<endl;
                  // cout<<tkey<<" "<<dict[tkey]<<endl;
                    mymap.erase(it);
                    dict.erase(tkey);
                    dict[key] = ++currPriority;
                    mymap[{key,dict[key]}] = value;
                }
            else
            {
               dict[key] = ++currPriority;
                mymap[{key,dict[key]}] = value;
            }
        }
      // cout<<key<<" "<<dict[key]<<" "<<mymap[{key,dict[key]}]<<endl;
    }
private:
    map<pair<int,int>,int,cmp> mymap;//{{key,priority},value}
    unordered_map<int,int> dict; //{key,priority}
    // unordered_set<int> myset;
    int maxSZ;
    int currPriority;
    // int currDictSZ;
    // int currQSZ;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
