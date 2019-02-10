class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
    }
    
    double next(int val) {
        if (mylist.size()==sz)
        {
            // auto it = mylist.begin();
            // mylist.erase(it);
            mylist.pop_front();
        }
        mylist.push_back(val);
        int sum = 0;
        for (auto val : mylist)
            sum += val;
        return sum/1.0/mylist.size();
    }
    list<int> mylist;
    int sz;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
