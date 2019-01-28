class TimeMap {
public:
    struct cmp
    {
      bool operator()(pair<string,int> p1,pair<string,int> p2)
      {
          if (p1.second==p2.second)
              return p1.first<p2.first;
          return p1.second<p2.second;
      }
    };
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (mymap.count(key))
        {
            priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> mypq = mymap[key];
            pair<string,int> p(value, timestamp);
            mypq.push(p);
            mymap[key]= mypq;
        }
        else
        {
            priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq;
            pair<string,int> p(value,timestamp);
            pq.push(p);
            mymap[key] = pq;
        }
    }
    
    string get(string key, int timestamp) {
           if (mymap.count(key))
           {
               auto pq = mymap[key];
               // for (auto it=pq.begin(); it!=pq.end(); it++)
               // {
               //     if (it.second<timestamp))
               //         return it.first;
               // }
               while (!pq.empty())
               {
                   if (pq.top().second<=timestamp)
                       return pq.top().first;
                   pq.pop();
               }
               return "";
           }
            else
            {
                return "";
            }
    }
    private:
    //unordered_map<key,pq<pair<value,time>>>
    unordered_map<string,priority_queue<pair<string,int>,vector<pair<string,int>>,cmp>> mymap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
