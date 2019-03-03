class Solution {
public:
/*
There are N piles of stones arranged in a row.  The i-th pile has stones[i] stones.
A move consists of merging exactly K consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these K piles.
Find the minimum cost to merge all piles of stones into one pile.  If it is impossible, return -1.
*/
    int longestOnes(vector<int>& A, int K) {
        // int leftZero = 0;//record the left zero location
        int leftInd = 0;//record the current left index
        int zeroCnt = 0; //record the current number of zeros
        int res = 0; //record number of the so far longest subarry
        
        queue<int> zeroq;//a queue to store the zeros
        for (int i=0; i<A.size(); i++)
        {
            if (A[i]==0)
            {
                zeroq.push(i);
                zeroCnt++;                
            }
            if (zeroq.size()>K)
            {
                res = max(res,i-leftInd);
                //we need to do so, since the leftInd can be next zero, but can also be next 1, so it is just the next index after the current 0 index
                leftInd = zeroq.front()+1;
                zeroq.pop();
            }
            else if (i==A.size()-1)
                res = max(res,i-leftInd+1);
        }
        return res;
    }
};
