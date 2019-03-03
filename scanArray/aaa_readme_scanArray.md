1. subarraysWithKDistinct_tle.cpp: from url: https://leetcode.com/problems/subarrays-with-k-different-integers/
I use two for-loop to directly solve it by brute force with simple prunning, I use a set to count the distinct number of variables. This algorithm TLE.

2. subarraysWithKDistinct_bruteforce_pass.cpp: The exact same algorithm with 1, but this time it passes. The only differences is that I use a bool used array and a variable distCnt to record the number of distinct numbers. Remember we should open a used array before the for loops and we just reset the values in the first loop. This passes but the 1st tle, and it means that though unordered_set is O(1) insert but it costs more than than our created array. 

3. moveZeroes.cpp: Problem: Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Solution: It's easy to think about the idea, we use two pointers to scan the array, p0 indicates the leftmost 0, and p1 indicates the leftmost non-zero, but it is very important to make sure that p1 is on the right of p0, so I set p1 = p0+1.

4. maxSlidingWindow_faster.cpp: 
problem: Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
Solution: Remember the last winodw's maxVal and maxId. If the maxId is i-1, then we need to rescan the window beginning from i, otherwise, we just need to compare maxVal and nums[i+k-1].

5. productExceptSelf.cpp: product except self, with O(n) algorithm and cannot use division. 
Soltuion: scan from left to right, and then scan from right to left. scan from left to right, prod[i] = prod[i-1]\*nums[i-1]//avoid by nums[i] scan from right to left, prod[i] = prod[i]\*ac, where ac \*=nums[i+1]

6. longestOnesWithKchanges.cpp: 
Problem: There are N piles of stones arranged in a row.  The i-th pile has stones[i] stones.
A move consists of merging exactly K consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these K piles.
Find the minimum cost to merge all piles of stones into one pile.  If it is impossible, return -1.
Solution: use a queue to record the locations of zeros, when the q.size is larger than K, then we compute the current maxLength with i-leftInd and we update leftInd = q.front()+1; then q.pop().
