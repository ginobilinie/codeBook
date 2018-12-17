class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::set<vector<int>> mysets;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for (int i=0; i<len-3; i++)
        {  
           for (int j=i+1; j<len-2; j++)
           {
               int l=j+1,r=len-1;
               while(l<r)
               {
                   int currSum = nums[i] + nums[j] + nums[l] + nums[r];
                   if (currSum==target)
                   {
                       vector<int> myvec{nums[i],nums[j],nums[l],nums[r]};
                       mysets.insert(myvec);
                       l++;
                       r--;
                   }
                   else if (currSum<target)
                   {
                       l++;
                   }
                   else
                   {
                       r--;
                   }
               }
           }
        }
        vector<vector<int>> myvecs( mysets.begin(), mysets.end() );
        return myvecs;
    }
};
