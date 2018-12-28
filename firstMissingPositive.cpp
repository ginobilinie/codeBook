class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
        this is a clever problem, we have to take advantage of the property of the problem itself.
        we use the index of the vector to indicate whether this value existed or not
        However, if the value is larger than the size of the vector, we have to skip such value
        Note, it is valid to skip these larger-than-vector-size values, since we just need to find the 
        smallest positive value. If all the values are larger than vector-size, then the smallest missing positive
        value should be 1. if part of the value is larger tha vector-size value, which means the number of smaller-than vector size values are less than vector size. Thus,the smallest missing positive value should be within the vector-size.
        And in any case, the first missing positive value appeared in the 1-to-vector-size range. 
        To this end, we can use the index to indicate whether this value has appeared or not.
        */
        if (nums.empty())
            return 1;
        int len = nums.size(), ind=0, tmp;
        for (int i=0; i<len; i++)
        {
            if (nums[i]<=0)//shift the non-positive value to the front
            {
                tmp = nums[i];
                nums[i] = nums[ind];
                nums[ind] = tmp;
                ind++;
            }
        }
        int i;
        for (i=ind; i<len; i++)
        {
            if (abs(nums[i])>0&&ind+abs(nums[i])-1<len && nums[ind+abs(nums[i])-1]>0)//we only process those value are among [1,vector-size]
                nums[ind+abs(nums[i])-1] = - nums[ind+abs(nums[i])-1];
        }
        
        for (i=ind; i<len; i++)
        {
            if (nums[i]>0)
                return i+1-ind;
        }
        return i+1-ind;
    }
};
