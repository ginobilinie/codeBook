class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for (int i=0; i<sz; i++)
            hash.push_back(-1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        hash[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (hash[key]==-1)
            return -1;
        else
            return hash[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hash[key] = -1;
    }
    // int n =10;
    // vector<int> vect(100, 10); 
private:
    int sz = 1000000+1;
    // vector<int> mm(sz, -1);
    vector<int> hash;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
