class Solution {
public:
    //we first linearly merge the two sorted array
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int * arr = new int[len1+len2];
        int currInd1=0, currInd2=0, currInd=0;
        while(currInd1<len1 && currInd2<len2)
        {
            if(nums1[currInd1]<nums2[currInd2])
                arr[currInd++] = nums1[currInd1++];
            else
                arr[currInd++] = nums2[currInd2++];
        }
        while(currInd1<len1)
        {
            arr[currInd++] = nums1[currInd1++];
        }
        while(currInd2<len2)
        {
            arr[currInd++] = nums2[currInd2++];
        }
        double midV;
        if ((len1+len2)%2)
            midV = arr[(len1+len2)/2]; 
        else
            midV = (arr[(len1+len2)/2-1]+arr[(len1+len2)/2])/2.0;
            
        delete []arr;
        return midV;
    }
};
