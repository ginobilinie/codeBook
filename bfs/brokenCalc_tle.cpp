class Solution {
public:
    int brokenCalc(int X, int Y) {
        //bfs
        queue<int> myq;
        myq.push(X);
        int res = 0;
        unordered_set<int> myset;
        myset.insert(X);
        while(!myq.empty())
        {
            int sz = myq.size();
            for (int i=0; i<sz; i++)
            {
                int val = myq.front();
                myq.pop();
                if (val==Y)
                    return res;
                int t1 = val - 1;
                int t2 = val * 2;
                if (myset.count(t1)==0)
                    myq.push(t1);
                if (myset.count(t2)==0&&t2<=2*Y)
                    myq.push(t2);
            }
            res++;
        }
        return res;
    }
};
