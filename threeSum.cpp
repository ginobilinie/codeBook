class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        map<int,int> smap;
        vector<vector<int>> vecs;
        // sort(nums.begin(),nums.end());
        map<vector<int>, int> vmap;
        for (int i=0; i<len; i++)
        {
            if (smap.count(nums[i])>0)
                smap[nums[i]]++;
            else
                smap[nums[i]] = 1;
        }
        for (int i=0; i<len; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                int sum = nums[i]+nums[j];
                if (smap.count(0-sum)==0)
                    continue;
                else
                {
                     vector<int> vec;
                     if (!(nums[i]==(0-sum) ||nums[j]==(0-sum)))
                     {
                         vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(0-sum);
                         sort(vec.begin(),vec.end());
                         if (vmap.count(vec)==0)
                         {
                            vmap[vec] = 1;
                            vecs.push_back(vec);
                         }
                     }

                    else if (smap.count(0-sum)==2)
                     {
                         vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(0-sum);
                         sort(vec.begin(),vec.end());
                        if (vmap.count(vec)==0)
                         {
                            vmap[vec] = 1;
                            vecs.push_back(vec);
                         }
                     }
                    else
                        continue;
                }
            }
        }
           if (smap.count(0)>0 && smap[0]>2)
        {
            vector<int> vec;
            vec.push_back(0);
            vec.push_back(0);
            vec.push_back(0);
            vecs.push_back(vec);
        }
        return vecs;
    }
};
