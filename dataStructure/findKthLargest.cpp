class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     
        priority_queue<int,vector<int>,greater<int>> mypq;//min-heap
        for (int num : nums)
        {
            mypq.push(num);
            if (mypq.size()>k)
                mypq.pop();//pop the smallest one, and maintain the k largest one
        }
        return mypq.top();
    }
};
