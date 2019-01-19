class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size()<2)
            return 0;
        radixsort(nums, nums.size());
        int maxD = 0;
        for (int i=1; i<nums.size(); i++)
        {
            if (maxD<nums[i]-nums[i-1])
                maxD = nums[i]-nums[i-1];
        }
        return maxD;
    }
    
    // The main function to that sorts arr[] of size n using  
    // Radix Sort 
    void radixsort(vector<int>& arr, int n) 
    { 
        // Find the maximum number to know number of digits 
        int m = getMax(arr, n); 

        // Do counting sort for every digit. Note that instead 
        // of passing digit number, exp is passed. exp is 10^i 
        // where i is current digit number 
        for (int exp = 1; m/exp > 0; exp *= 10) 
            countSort(arr, n, exp); 
    } 

    // A function to do counting sort of arr[] according to 
    // the digit represented by exp. 
    //by dong nie
    void countSort(vector<int>& arr, int n, int exp) 
    { 
        vector<int> output(n); // output array 
        int i;
        unordered_map<int,vector<int>> mymap;

        // Store count of occurrences in count[] 
        for (i = 0; i < n; i++) 
        {
            int digit = (arr[i]/exp)%10;
            if (mymap.count(digit))
            {
                mymap[digit].push_back(arr[i]);
            }
            else
            {
                vector<int> vec;
                vec.push_back(arr[i]);
                mymap[digit] = vec;
            }
        }

        // Build the output array 
        int ind = 0;
        arr.clear();
        for (i = 0; i<10; i++) 
        { 
            if (mymap.count(i))
            {
                vector<int> tmp = mymap[i];
                for (int j=0; j<tmp.size(); j++)
                {
                    arr.push_back(tmp[j]);
                }
            }

        } 
  
    } 
    
    int getMax(vector<int>& arr, int n) 
    { 
        int mx = arr[0]; 
        for (int i = 1; i < n; i++) 
            if (arr[i] > mx) 
                mx = arr[i]; 
        return mx; 
    } 
};
