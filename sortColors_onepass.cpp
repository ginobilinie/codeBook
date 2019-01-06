class Solution {
public:
    void sortColors_onepass(vector<int>& nums) {
        if (nums.empty())
            return;
        int sz = nums.size();
        int l=0, r=sz-1, anchor=0;//anchor means the current focus point
        
        int tmp;
        while (l<r && anchor<r)
        {
              if (nums[anchor]==0 && anchor!=l)
              {
                  tmp = nums[anchor];
                  nums[anchor] = nums[l];
                  nums[l] = tmp;
                  l++;
                  anchor++;
              }
              else if (nums[anchor]==1)
              {
                  anchor++;//to encounter the first 0 or 2
              }
            else 
            {
                tmp = nums[anchor];
                nums[anchor] = nums[r];
                nums[r] = tmp;
                r--;
                //anchor++;
            }
        }
            
    }
};
