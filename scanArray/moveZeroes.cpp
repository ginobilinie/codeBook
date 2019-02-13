class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty())
            return;
        // int l = 0, r = nums.size()-1;
        //l to indicate the leftmost 0, and r to indicate the rightmost 1
        //this way will break the order of the non-zero numbers
        // while (l<r)
        // {
        //     while (l<r&&nums[l]!=0)l++;
        //     while (r>l&&nums[r]==0)r--;
        //     int tmp = nums[l];
        //     nums[l] = nums[r];
        //     nums[r] = tmp;
        //     l++;
        //     r--;
        // }
        //p0 indicates the leftmost 0, p1 indicates the leftmost 1 from the current position on
        int p0=0, p1 =0, sz=nums.size() ;
        while (p0<sz&&p1<sz)
        {
            while (p0<sz&&(p0+1)<sz&&nums[p0]!=0) p0++;
            if (p0+1<sz)
                p1 = p0 + 1;
            else
                break;
            while (p1<sz&&(p1+1)<sz&&nums[p1]==0) p1++;
           
            //swith p0 and p1

            int tmp = nums[p0];
            nums[p0] = nums[p1];
            nums[p1] = tmp;                


            if (p0==sz-1||p1==sz-1)
                break;
            // p0++;
            // p1++;
        }
        
    }
};
