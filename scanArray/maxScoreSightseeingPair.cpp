class Solution {
public:
   
    /*
    Problem: Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot, and two sightseeing spots i and j have distance j - i between them.
    Solution: prevEqualMax is the current max value when we considering counteracting the distance effect: prevEqualMax = max(currVal, prevEqualMax-1); note the prevEqualMax-1 is the one considering counteracting the distance effect
    Then, we can maintain a maxScore to track the current max value of A[i]+A[j]+i-j
    */
    int maxScoreSightseeingPair(vector<int>& A) {
        int prevEqualMax = A[0];
        int maxScore = 0;
        for (int i=1; i<A.size(); i++)
        {
            maxScore = max(maxScore, prevEqualMax+A[i]-1);
            prevEqualMax = max(A[i], prevEqualMax-1);
        }
        return maxScore;
    }
};
