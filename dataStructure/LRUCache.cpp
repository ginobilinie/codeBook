class LRUCache {
public:
    LRUCache(int capacity)
    {
        maxSZ = capacity;
        // currDictSZ = 0;
        // currQSZ = 0;
    }
    
    int get(int key)
    {
        for (auto it: mymap)
            cout<<it.first<<" ";
        if (mymap.count(key))
        {
            int tmp = mymap[key];
            mymap.erase(key);
            mymap[key] = tmp;
            return mymap[key];   
        }
        else
            return -1;
    }
    
    void put(int key, int value)
    {
        if (mymap.count(key))
        {
            int tmp = mymap[key];
            mymap.erase(key);
            mymap[key] = value;
        }
        else//no such a key
        {
            if (mymap.size()<maxSZ)
            {
                mymap[key] = value;
            }
            else
            {
                //erase the first in (the beginning value)
                mymap.erase(mymap.begin());
                mymap[key] = value;
            }
        }
    }
private:
    unordered_map<int,int> mymap;
    // unordered_set<int> myset;
    int maxSZ;
    // int currDictSZ;
    // int currQSZ;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
