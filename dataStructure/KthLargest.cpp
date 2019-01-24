class KthLargest {
public:
   public:
    KthLargest(int k, vector<int> nums) {
        maxSz = k;
      for (int val : nums)
      {
          myq.push(val);
        if (myq.size()>k)
              myq.pop();
      }
    }
    
    int add(int val) {
        myq.push(val);
        if (myq.size()>maxSz)
            myq.pop();
        return myq.top();
    }

private:
     int maxSz;
    priority_queue<int,vector<int>,greater<int>> myq;//less is big heap, greater is small heap
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
