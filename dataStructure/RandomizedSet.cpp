class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (myset.count(val))
            return false;
        myset.insert(val);
        return 1;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!myset.count(val))
            return false;
        myset.erase(val);
        return 1;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int sz = myset.size();
        if (sz==0)
            return 0;
        int ind = rand() % sz;
        // cout<<ind<<endl;
        auto it = myset.begin();
        advance(it, ind); 
        int res = *it;
        return res;
    }
    
    unordered_set<int> myset;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
