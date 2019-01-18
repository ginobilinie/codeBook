class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        // minVal = INT_MAX;
    }
    
    void push(int x) {
        if (vec.empty())
        {
            pair<int,int> p(x,x);
            vec.push_back(p);
        }
        else
        {
            pair<int,int> p(x,min(x,getMin()));
            vec.push_back(p);
        }
    }
    
    void pop() {
        if (!vec.empty())
        {
            vec.pop_back();
        }
    }
    
    int top() {
        if (!vec.empty())
            return vec[vec.size()-1].first;
        else
            return -1;
    }
    
    int getMin() {
        return vec[vec.size()-1].second;
    }
    
private:
    vector<pair<int,int>> vec;
    // map<int,int> mymap;
    // int minVal;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
