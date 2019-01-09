class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m==0)
        {
            nums1 = nums2;
            return;
        }
        int p1=0, p2=0;
        int dm = m;
        while (p1<dm&&p2<nums2.size())
        {
            while (p1<dm&&nums1[p1]<=nums2[p2])
                p1++;
            nums1.insert(nums1.begin()+p1,nums2[p2]);
            dm++;
            //p1++;
            p2++;
        }
        while (p2<n)
        {
            nums1.insert(nums1.begin()+m-1+n-p2,nums2[p2++]);
        }
        while (nums1.size()>m+n)
            nums1.pop_back();
    }
};
