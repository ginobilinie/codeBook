class Solution {
public:
    set<int> myset;
    void dfs(int len, int diff, int currNum, int currDigit, int currLen)
    {
        if (currLen==len)
        {
            myset.insert(currNum);
            return;
        }
        int tmp;
        if (currDigit-diff>=0)
        {
            tmp = currNum;
            currNum = currNum*10 + currDigit - diff;
            dfs(len, diff, currNum, currDigit-diff, currLen+1);
            currNum = tmp;
        }
        if (currDigit+diff<=9)
        {
            tmp = currNum;
            currNum = currNum*10 + currDigit + diff;
            dfs(len, diff, currNum, currDigit+diff, currLen+1);
            currNum = tmp;           
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if (K==0)
        {
            vector<int> rr;
            if (N==1)
            {
                for (int i=0; i<10; i++)
                    rr.push_back(i);
                return rr;
            }

            int ss=0;
            for (int i=1; i<=9; i++)
            {
                ss=0;
                for (int j=0; j<N; j++)
                    ss = ss*10 + i; 
                rr.push_back(ss);
            }
            return rr;
        }
        
        if (N==1)
        {
            vector<int> rr;
            for (int i=0; i<10; i++)
                rr.push_back(i);
            return rr;
        }
        for (int i=1; i<10; i++)
        {
            dfs(N, K, i, i, 1);
        }
        vector<int> res(myset.begin(), myset.end());
        return res;
    }
};
