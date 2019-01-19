class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size()==0)
        {
            return {};
        }
        vector<int> vec;
        int l=0, r=numbers.size()-1;
        bool flag = 0;
        while (l<r)
        {
            int data = numbers[l]+numbers[r];
            if (data==target)
            {
                vec.push_back(l+1);
                vec.push_back(r+1);
                flag = 1;
                break;
            }
            else if (data>target)
            {
                r--;
            }
            else //data<target
            {
                l++;
            }
        }
        if (!flag)
            return {};
        return vec;
    }
};
