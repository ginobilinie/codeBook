class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int x) {
        vec.push_back(x);
        // if (x<minVal);
        //     minVal = x;
    }
    
    void pop() {
        //but we have to update he minVal
        if (!vec.empty())
            vec.pop_back();
    }
    
    int top() {
        if (!vec.empty())
            return vec[vec.size()-1];
        else
            return -1;
    }
    
    int getMin() {
        //we can use for loop to get the smallest one, but it is then O(n)
        //if we like to have O(1) for getMin, we need a priority queue
        int res = INT_MAX;
        for (int i=0; i<vec.size(); i++)
            if (vec[i]<res)
                res = vec[i];
        return res;
    }
    
private:
    vector<int> vec;
    int minVal;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
