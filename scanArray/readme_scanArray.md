1. subarraysWithKDistinct_tle.cpp: from url: https://leetcode.com/problems/subarrays-with-k-different-integers/
I use two for-loop to directly solve it by brute force with simple prunning, I use a set to count the distinct number of variables. This algorithm TLE.

2. subarraysWithKDistinct_bruteforce_pass.cpp: The exact same algorithm with 1, but this time it passes. The only differences is that I use a bool used array and a variable distCnt to record the number of distinct numbers. Remember we should open a used array before the for loops and we just reset the values in the first loop. This passes but the 1st tle, and it means that though unordered_set is O(1) insert but it costs more than than our created array. 

3. moveZeroes.cpp: Problem: Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Solution: It's easy to think about the idea, we use two pointers to scan the array, p0 indicates the leftmost 0, and p1 indicates the leftmost non-zero, but it is very important to make sure that p1 is on the right of p0, so I set p1 = p0+1.

4. maxSlidingWindow_faster.cpp: 
problem: Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
Solution: Remember the last winodw's maxVal and maxId. If the maxId is i-1, then we need to rescan the window beginning from i, otherwise, we just need to compare maxVal and nums[i+k-1].

5.
