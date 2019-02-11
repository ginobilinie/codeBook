class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for (int i=0; i<sz; i++)
            hash.push_back({i,-1});
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int tmp = key;
        key %= sz; //simple modular operation 
        while (hash[key].second!=-1&&tmp!=hash[key].first) //solve the potential collisions with a linear function
        {
            key = (key+1)%sz;
        }
        hash[key] = {tmp,value};
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int tmp = key;
        key %= sz;
        if (hash[key].second==-1)
            return -1;
        else
        {
            while (hash[key].second!=-1&&tmp!=hash[key].first)
            {
                key = (key+1)%sz;
            }            
            return hash[key].second;            
        }

    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int tmp = key;
        key %= sz;
        while (hash[key].second!=-1&&tmp!=hash[key].first)
        {
            key = (key+1)%sz;
        }
        hash[key] = {tmp,-1};
    }
    // int n =10;
    // vector<int> vect(100, 10); 
private:
    int sz = 10000+1;
    // vector<int> mm(sz, -1);
    vector<pair<int,int>> hash;//our hash can store hashed_key -> (key, value)
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
