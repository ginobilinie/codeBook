class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        map<int,int> mymap;
        for (int a: A)
        {
            if (mymap.count(a))
                mymap[a]++;
            else
                mymap[a] = 1;
        }
        int cnt = 0;
        for (auto it : mymap)
        {
            if (it.second>1)
            {
                mymap[it.first+1] += it.second - 1;
                cnt += it.second - 1;
            }
        }
        return cnt;
    }
};
