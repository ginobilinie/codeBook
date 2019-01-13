# codeBook
for fun, forever

codes for poj. all C++ codes.

1. bfs.cpp: my solution for poj 3984. BFS for shortest path, and recursively trace back the path. I remebered a lot for solving it: how to define mutli-dim vector, how to define queue, how to define struct array, how to define direction, how to write BFS, how to trace path. Note, BFS is not implemented recursively itself (in contrast, DFS is usually implemnted in a recursive way).

2. unionSet.cpp: my solution for poj 2524. Simple application of Union Set. I memorized that time we prepared for ACM/ICPC contest. I re-learned how to implement a Union Set: makeSet, findSet, unionSet. Two keypoints: update root node along the trace path when union for a coming pair by finding operation (压缩路径); combine two subsets according to the rank (按秩合并).

3. binSearch.cpp: I wrote sample codes for binary search. Remeber to finish while loop when finding the target.

4. dfs.cpp: A poj problem (3050). DFS is quite commonly used. Remember the trace back after dfs. Here we donot need to use used to remember the visiting status like BFS. 

5. treeBuild.cpp: A poj problem (1577). Build a tree and then preorder traverse it. Given some specific information about a tree, and then ask you to build the that tree, such as, given two of post-order/pre-order/mid-order traverse sequences, ask you to inference the rest one's sequence. In this problem, the tree is BST, so the problem is much easier. And here I use a integer to simulate real pointer, actually it will be very cool if I use real pointer.

6. treeBuildwithBFSoutput.cpp: A problem for 3367. Build a tree according to post-order traverse, and then output the tree from down-to-up, right-to-left. The 1st part is easy done with Stack, the 2nd part should be done with BFS visit, and the reverse the visited sequence. Note, we use the integer to simulate the real pointer, and push the node index to the stack/queue, this makes the problem much easier. 

7. TwoSum: brute force or hash table. Note how to use vector<type> and map<type_key, type_value>. push_back for vector, and insert(<std:pair<type_key,type_value>(key,value)) for map, and count(key) for map.

8. addTwoNumbers: The logic is easy. But it is not easy to make it pass the OJ. Be familiar with the link-list and struct operation. Also, it is very important to note the update order when you use linked-list: we should update the value of next pointer prior to the current one (otherwise, the value of the current pointer will be covered.

9. longestSubstring4unrepeatedChars: The logic is easy, but we should notice the detaisl, for example, empty string. Also, insert for vector is push_back function instead of vec[i]=val. As for the logic, we should better maintain the current the longest substring to the current index (for simplexity and time, we use a map and a unrepeated starting index to this character) and a global max legnth to simulate it.

10. media4TwoSortedArrays: I linearly combine two sorted arrays into one sorted array. But it is O(n) time. We need another solution for log(m+n).

11. longestPalindrome.cpp: The main point is to loop around each element: check the left-right elements around each element, and we also should consider odd/even cases.

12. zigzag.cpp: inference the simple math rule. Also, pay attention to case when numRows==1.

13. reverseNum.cpp: easy logic. However, we should know for signed integar, the range is 2^31-1 and -2^31, in C++ words, INT_MAX and INT_MIN.

14. myatoi.cpp: easy logic. However, we should pay attention to the overflow case, and I use long long for the temporary result.

15. roman2Int.cpp: easy logic. We'd better build a ordered Roman item dictionary.

16. maxArea.cpp: brute force: Directly scan through the array. A better way is to maintain two pointers from left side and right side respecitvely, and always update the lower side untile left encounter the right.

17. int2Roman.cpp: list each possible Roman basic units and form a ordered dictionary.

18. longestCommonPrefix.cpp: find the shortest word, and then scan it.

19. threeSum.cpp: I give a O(n^2) algorithm with using map. One thing we should pay attention to is map.count(x) is sth like find, it will not return the exact number of the target element, instead, it will return 0 if not found, and 1 if found; and if we want to get the number of the target element, we should better use map[target_element]. I first write a O(n^3) algorithm, but TLE. The goolged solutions are usually: first sort, and then fix a value, then use two pointers (i,j) to specify left and right side in a while loop.

20. threeSumClosest.cpp: Brute force, a three-loop to solve it, but pay attention to empty cases. A faster solution O(n^3) is to fix a value, and then use two pointers (one from the left side from the just fixed value, and the other from the right side) to scan the array. Of course, we should first sort the array. If the sum is smaller than the target, which means we should enlarge the sum, so we should move left pointer to right, if the sum is larger than the target, then we should decrease the sum, which means we should move right pointer to the left.

21. letterCombinations.cpp: a simple dfs. Note to consider empty input "".

22. foursum.cpp: O(n^3) algorithm. two basic for loop, and one while (l<r) loop. std::set<vector<int>> mysets. mysets.insert(xx) which will automatically insert non-duplicate items. Also, set to vector: vec(myset.begin(),myset.end()).
  
23. removeNthFromEnd.cpp: Learn to operate on linked list. Pay attention to the exceptional case: remove the 1st one.

24. isValidParenthes.cpp: How to use stack, empty() function, and we also specify template. Also, we need to consider all cases, such as only left brackets or only right brackets.

25. mergeTwoLists.cpp: merge two sorted lists. When we encounter same value , we use head-in insert manner. Note to update the current pointer in progress.

26. generateParenthesis.cpp: Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. The key point is to find what's the invalid cases: if closing (right) bracket is more than the openning (left) bracket, then it is invalid. Otherwise, it is valid. Based on this observation, we can simply write the codes.

27. mergeKLists.cpp: use priority_queue to maintain a k-min heap (k is the number of lists), and we should learn how use priority_queue, like priority_queue<type, container, compare>. Also, we should be very careful about the pointer operation. Time complexity: nk*log(k), and space complexity: O(k)

28. swapPairs.cpp: pay attention to the end condition for while loop.

29. reverseKGroup.cpp: this is a harder version of swap pairs. We first compute the length of the list, and seperate this list into several groups and possible remainnings, we reverse each group and connect between groups, followed by the possible remainings.

30. removeDuplicates.cpp: remove sth from sorted array. Note how to delete a number from a vector: vec.erase(vec.begin()+pos), and the vector size will change immediately.

31. removeElement.cpp: Note how to delete a number from a vector: vec.erase(vec.begin()+pos), and the vector size will change immediately.

32. strStr.cpp: Pay attention to the "" and "" case.

33. divide.cpp: note for the overflow case. Also, this is a while-loop method and it costs too much time.

34. divide_faster.cpp: same problem as 33, but much faster algorithm with left move operator. I first find the possible largest number of times that the divisor can be left move operated. Then we minus the largest left moved divisors, folled by the second largest if possible. Note for the overflow case.

35. repeatedNTimes.cpp: easy. We can first sort, and then check the repeat one.

36. maxWidthRamp.cpp: a very good problem. We first use struct to rewrite it, and sort according to the value (of course, when value equals, we sort by index). Then we just need to find the largest gap in an array from left to right. Again, we use 贪心算法，this is a little tricky, since we have to maintain the minimum index and the largest gap when we scan the array.

37. findSubstring.cpp: You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters. This is an interesting problem. I use the quite direct idea to make it. And I sort the temporary word dictionary and use binary search to find we get the current unit, and we erase the found item for the temporary word dictionary. However, this method is a little slow. 

38. nextPermutation.cpp: To find the next permutation sequence, we have to first locate the rightmost lInd so that lInd<rInd and A[lInd]<A[rInd], and then we switch. Later on, we sort the array from lInd+1 on.

39. searchInsert.cpp: Search the proper location for a insertion or the correct index for a given value for a sorted array.

40. biSearchRotatedSortedArray.cpp: The key point is to judge which part of the array is the well sorted part. And we make comparison and decision based on these well sorted part. Also, we can first biSearch the largest value, and then make a regular biSearch over the reasonable region.

41. searchRange.cpp: For a sorted array, we have to find the left and right index for a given value (range). We write two biSearch functions, one biSearchLeft, and one biSearchRight: the key point is that we donot stop when we first encounter the target value. 

42. longestValidParentheses.cpp: Note, the problem is to find the longest valid substring of parentheses. I use a vector to record where the break point should be, and I use a begin-to-end scan for the string and also use a end-to-begin scan for the string to decide where the break points should be. Note, left number of Parentheses should always be greater than that of the right side in a begin-to-end scan. After we have the break points, it is easy to do count the maximum length of the substring.

43. isValidSudoku.cpp: Directly following the definition, and then form the algorithm to detect each possible subbox or row or column.

44. solveSudoku.cpp: backtracking. A good problem to practice backtracking. Note for the end condition, also, we should pay attention to that when there is a solution, we should end the search, which means we should set a flag to stop the backtracking. We can continue to optimze the time for the validation part: we can maintain three two-dim array for checking if each value in a row/colum/box is used or not.

45. countAndSay.cpp: stupid question. The nth term is a read-off based on the n-1-th term.

46. combinationSum.cpp: no repeated number in the input array, but allow repeated number in each possible comibinations (which means each input number is allowed for unlimited use). typical dfs. Pay attention to the backtracking recovery and the usage of set (including convert to vector).

47. combinationSum2.cpp: may contain repeated number in the input array, but each input number is only allowed for one time use. typical dfs. Pay attention to the backtracking recovery and the usage of set (including convert to vector). The difference from 46 is the currInd.

48. stringMultiply.cpp: multiplies two big string. We proprcessed the carry (进位) in the final step. Also, note for 0. 

49. firstMissingPositive.cpp: This is a typical question about how to use index to flag some value has visited or not. Usually, we can open an extra array used[maxVal] to denote whether which values have been visited. However, the maxVal can be huge, so we can only care about the ones we want to care about (here means we use a map). While for this problem, we are only allowed to use constant extra space, thus, we take advantage of the input array itself. The key points are: shift non-positive values to the left, and we begin from the first positive value; we set the visited value, like 3, nums[3-1] = - nums[3-1] (if nums[3-1] is original positive), this design is critical, because we can still consider nums[3-1] in later encounter by using a abs function. 

50. trapTheRain.cpp: a TLE solution: we increase the valid minimum by 1 each time, or a evolutionary one: we increase the minimum by to a second minimum each time. This algorithm takes about O(n^2) time.

51. trapTheRain_faster.cpp: We first find the max value and the index for this max value. We go from left and right. From left side, we start from a current point (e.g., index 0), if the next point's value is smaller than the current point, we use the current point's value-next point's value to increase the trap rain, and then we forward the next pointer till we encounter an next pointer whose value is larger than the current value, and we set the current value to such next pointer and go on... This algorithm takes about O(n) time complexity.

52. wildcardMatching.cpp: a failure solution using while loop to scan it.

53. permute.cpp: distinct input integers. typical dfs for permutation. Note to use used array to check if this value has been used or not. Also, for vector, avoid using erase as much as possible, instead, we can use a tmp to remember the previous status for later recovery. Actually, we can use pop_back to pop the last element from the vector.

54. permuteUnique.cpp: input integars may contain duplicate numbers. 1. we use set to avoid the repeated cases, however, it is slow.

55. permuteUnique_faster.cpp: input integars may contain duplicate numbers. We first sort the input array. And then we use a simple while loop to find next distinct number (note this while loop should placed in the end of the for loop, since we should consider the repeated numbers before we begin with this repeated number) and we consider from it for next iterations.

56. rotateImage.cpp: rotate a image by 90 degree in a clockwise manner. We have to change the corresponding 4 related locations at the same time. Also, pay attention to the for loop conditions.

57. spellchecker.cpp: a interesting problem. Use three map to cover all cases. Most importantly, to deal with certain general match of a string, like 'a', 'o', 'i', 'e', 'u', we can use '?' to replace these letters in dictionaries and the queries.

58. numsSameConsecDiff.cpp: a simple dfs, with considering the boundary conditions.

59. isSameValueTree.cpp: a simple traverse algorithm.

60. minCameraCover.cpp: Given a binary tree, we install cameras on the nodes of the tree. Each camera at a node can monitor its parent, itself, and its immediate children. Calculate the minimum number of cameras needed to monitor all nodes of the tree. Proposed solution is defining three statused for a current node (not covered, no needed to be covered and has covered). And we design a preorder traverse with greedy algorithm: if left and right child nodes are both not covered, then we set camera for the current node; if one of left or right childe nodes has been covered, then we donot neede camera for the current node; otherwise, there is no camera (for leaf nodes). 

61. groupAnagrams.cpp: use map and convert map to vector in final step.

62. myPow.cpp: simple Divide-and-Conquer algorithm. Note to take advantage of the computed value as much as possible. O(logn). Note the 0 cases.

63. maxSubArray.cpp: simple dp algorithm: just consider the previous node's value.

64. solveNQueens.cpp: solve n queens. Typical backtracking or dfs. Pay attention to correctly understand the rule of N queens. Note we should only check the has been visited regions to save time.

65. totalNQueens.cpp: same as 64. We even donot need to return the exact solutions but the number of solutions.

66. spiralOrder.cpp: define the left, right, top and down for convenience. 

67. canJump.cpp: a dfs algorithm, but TLE.

68. canJump_faster.cpp: linear algorithm. Use a currMaxReachInd to indicate the maxmimum reachable index for the current visit index. Pay attention to that if the currMaxReachInd is smaller than the current visit index, we should break the scan.

69. mergeInterval.cpp: first sort the intervals. And then combine them if necessary. 

70. insertIntervals.cpp: we can first insert and then merge.

71. lengthOfLastWord.cpp: pay attention to unusual case: spaces in the end of the string.

72. generateMatrix.cpp: generate a matrix which follows a spiral way.

73. getKthPermutation.cpp: given n, get the k-th permutation sequence. In this copy, I write a simple dfs to solve it. However, it is very slow.

74. getPermutation_faster.cpp: using simple analysis to decide the value for each position one by one.

75. rotateRightList.cpp: simple Linked list operation. Seperate it to two parts and then reorganize the list.

76. uniquePaths.cpp: actually the possible ways is C(m+n-2,m-1). Then we just need to compute the combination number. Also, we can also use a DP to do it.

77. uniquePathsWithObstacles.cpp: when we encounter the obstacles, we set the dp[i][j]=0, pay attention to the first row or first column if the obstacle appears.

78. minPathSum.cpp: two dimension DP. Actually, we can further use one-dim dp, but also with O(n^2) time complexity.

79. plusOne.cpp: simple array based number process.

80. addBinary.cpp: binary bits addition.

81. mySqrt.cpp: newton iteration methods to solve the equation: f(x) = x^2 - a = 0; x1 = x0 - f(x0)/df(x0)

82. mySqrt_biSearch.cpp: binary search, use x/mid vs mid.

83. climbStairs.cpp: Fibonacci sequence.

84. simplifyPath.cpp: string process for the file path.

85. minPathSum_linearSpace.cpp: dp[i] means the min path sum for the ith column of the current's row.

86. minEditDistance.cpp: the minimum edit distance. We use a two-dim dp array, dp[i][j] means the minimum edit distance from word1[0...i] to word2[0...j]. The state transfer equation: if (word1[i]==word2[j]) dp[i][j] = dp[i-1][j-1] else dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1. For initialization, we consider dp[0][i] and dp[i][0].

87. setZeroes.cpp: Set an identifier. Howerver, this solution has a chance to fail. We can also set a row[] and col[] to record the zero places, but it will cost O(n) space complexity. A better solution (setZeroes_better.cpp): I find the last row which has 0, and use it to store the 0-collumns.
Then go row by row set them to 0. Then go column by column set them to 0. Finally set the last row which has 0. It's long but hey it's O(1).

88. searchMatrix.cpp: 2D binary search. Using 1D idea to do it, and we convert mid to row,col pair at each time.

89. sortColors.cpp: use two pass for loop. I'll further write a one-pass for-loop, which is in sortColors_onepass.cpp, we set three indexes: left, right and anchor.

90. flipMatchVoyage.cpp: 971

91. isRationalEqual.cpp: to judge if two given rational number (youlishu) is equal or not. A very complex string process. Stupid!!! Note: 1. double's precision is far less than enough (e.g., double a = 99.99, actually, in memory, it may store as 99.99999.." 2. 1.9(9) is equal to 2.0....

92. combine.cpp: we write a dfs to produce the combination nums. If it is <b>combination</b> data, then we donot need used array. If it is <b>permutation</b>, then we should better use used array to indicate which value has been used.

93. subsets.cpp: simple combination problem: to print all the subsets of a given integer array. No used array needs to be used.

94. exist.cpp: to check if a board exist a given word. Simple dfs. If they say the basic unit (like digit/character) cannot be used twice, then we should better use used array. 

95. removeDuplicates_v2.cpp: Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length. From end to front with using vector.erase.

96. biSearchRotate.cpp: Compare with the biSearchRotatedSortedArray.cpp (40), the key point here is that we have duplicates in the array, especially the cases the duplicates appear in the start and end side, we should first process one side, then we can really decide which part is the increasing part. When we have processed the duplicates issues, we can then easily judge if left is ordered part or right side is ordered part, after ordered part is determined, we can then further judge where the target is located.

97. deleteDuplicates_v2.cpp: use three pointers to do it. Pay extra attention to the head duplicated cases.

98. deleteDuplicates_v1.cpp: a easier problem for 97.

99. largestRectangleArea.cpp: use two for loop to brute force compute the maximum value.

100. largestRectangleArea_v1.cpp: problem same as 99 (leetcode84). use stack to solve this kind of problem is great. However, this method is quite tricky, though its complexity is O(n). Need understand more.

101. maximalRectangle_failure_dp.cpp: a failure dp for maximual rectangle problem.

102. maximalRectangle.cpp: Here we write a simple O(n^3) method by recording each row's consecutive 1s. And we compute row by row, I mean, when we deal with one row, we should take care of rows before this row, which is, the number of colums to have all 1s till this colums across prevRows to this current row, then the area should be (currRow-prevRow+1)*minConsecutiveColumns.

103. partitionLinkedList.cpp: use two pointers to maintain two sub linked list with tail insert, and we combine them together in the final step.

104. isScramble.cpp (leetcode87): A very interesting problem, also a type of tree child nodes switch problem. We cannot solve this problem with the tree traverse idea, since if we just know the preorder traverse sequence, then we cannot actually recover the tree since many possibilities exist. Thus, we should better think it in another way: we should just compare that in each level of partitions, if there are a possible correct way for s1 to dictionary (I mean char match without considering sequence) match s2? Thus, we need to consider all the levels of partitions (in each level, only one partion is correct, then this level is correct), so we use recursive calling.  

105. mergeSortedArray.cpp: a stupid problem. The idea is easy: maintain two pointers to merge the two arrays. Pay attention to corner keys that the first array is empty. I'm now still quite understanding: why vec.insert(vec.begin(),10) can fail...

106. grayCode.cpp: bit operation. Find some basic law, and use bit operation to left move. x<<=1, x= x<<1;

107. subsetsWithDup.cpp: This is a typical question about dfs with duplicate cases. In each dfs level, we need to use a while loop to eliminate the remaining duplicates after this dfs level, since we donot like to waste dfs with duplicate begainings.

108. numDecodings.cpp: A dp problem: to check if the s[i] can be combined with s[i-1] or not, and it can form a danymic status equation. However, we should pay attention to 0, without the '0' included corner case, this is a ordinary medium problem.

109. reverseLinkedListBetween.cpp: use tail0, head1, tail1, head2 to partition the linked list to 3 parts. Pay attention to the m is the head case.

110. restoreIpAddresses.cpp: Using the skip step as the base to form the for loop, and pay attention to corner cases, like '025', like '744' and so on.

111. inorderTraversal.cpp: convert preorder traverse to inorder traverse.

112. generateTrees.cpp: given a number, generate all the possible binary search trees. This is a very good and important problem. Note only about the recurse idea, but also about combine all possible left Trees (l to i-1) and corresponding right trees (i+1 to r) to form a new tree rooted at (i). More importantly, since the vector may be huge, we should better use * type as return value. Of course, we can also use reference type as function parameter.

113. generateTrees_referenceVersion.cpp: same with 112, but we use reference type as a instead. However, it seems it costs 20ms (16ms if using pointer). 

114. numTrees.cpp: following 112 and 113, easier one, to compute the number of possible bst trees given a number. Solved by a dp with recursive function: 
f(n) = sigma_k_1_to_n (f(n-k)*f(k-1)). However it is quite slow, cost about 2980ms, because it repeated compute the same number.

115. numTrees_faster.cpp: same as 114. Instead of recursive function, we use a vector to store the values, and we run from 0 to n so that we can avoid the repeated computation.

116 (leetcode 97). isInterleave.cpp: Given s1, s2, s3, find whether s3 is formed by the interleaving (from left to right order for both s1 and s2) of s1 and s2. We design a dp to solve it: dp[i][j] = s3[i+j-1]==s2[j-1]&&dp[i][j-1]||s3[i+j-1]==s1[i-1]&&dp[i-1][j]. For initialize, we initialize dp[0][j] and dp[i][0] which means we only use characers from s1 or s2. Here, dp[i][j] means using the first i characters from s1 and the first j characters from s2 can be interleaved form s3[i+j-1] or not. Here is a trick, we using dp[len1+1][len2+1] since we leave the 0's rom (column) means using nothing from the s1 or s2.

117. isValidBST.cpp: to check if the given btree is a valid bst or not. We first in-order traverse the tree, and check if the resulted array is rigously asending ordered or not.

118. isSameTree.cpp: traditional preorder traverse.

119. recoverTree.cpp: recover the BSTree without chaning the tree's structure. I use a stupid method: we first in-order traverse the tree, and result in a vector, and then we sort the vector, in the end, we in-order traverse the tree again and assign values for the nodes. It costs about 80ms. O(n) time and O(n) space.

120. recoverTree_constantSpace.cpp: sam as 119, but with constant space O(1), the time complexity is O(n). The idea again is in-order traverse. It maintains a prev node to remember the just-now-visited node, and the root is the current visited node. if current node's value is smaller than the just-now-visited node (which means the first violated order node), then we should remember it as the firstViolatedNode, but we should not switch them immediately, since there may later violations, if there are indeed some later violations, then we should update the lastViolatedNode, and we finally swith the firstViolated and lastViolated node in the final step.  **since there are only two elements wrongly swapped, so we should remember the first out of order value (should be bigger) and the last out of order value (should be smaller). However, this algorithm only suits for there are only two wrongly swapped nodes.

121. isSymmetricTree.cpp: to judge if a tree is symmetric or not. Use recursive method. 

122. levelOrder.cpp: traverse the tree in level order, and we should put elements of each level in a same vector. I write it using bfs, with two queue, one queue stores the TreeNode*, another one stores the level id.

123. zigzagLevelOrder.cpp: similar with 123, but in a zigzag manner. The solution is quite similar with 122, but we just need to use a variable cnts to measure whether it is in odd or even line.

124. maxDepth.cpp: max depth of a tree.

125. buildTree.cpp: build a tree based on preorder and inorder traverse sequence. Use preoder to determine the head, and use inorder to determine the partition. And it can be easily write a recursive method. Note how to use vector<int> vec(myvec.begin(), myvec.begin()+1) can just give the a new vector containing the 1st element of myvec. Actually, we can also use index (l and r) to show virtually parttition the vector to two parts, but this may not easy to decide the head in this case.

  
126. buildTree_v2.cpp: build a tree based on postorder and inorder traverse sequence. Use postorder to determine the head, and use inorder to determine the partition. And it can be easily write a recursive method. Note how to use vector<int> vec(myvec.begin(), myvec.begin()+1) can just give the a new vector containing the 1st element of myvec.

127. levelOrderBottom.cpp: traverse the tree in level order, and we should put elements of each level in a same vector. I write it using bfs, with two queue, one queue stores the TreeNode*, another one stores the level id. Then we reverse the result vector.

128. sortedArrayToBST.cpp: sorted array to height balanced BSTree. We just use the mid to create a new head, and the partition the problem to two subproblems (left and right), and we can result in a elegant recursive code. Instead of manully partition the vector to the parts like 125 and 126, we can use index (l and r) to show virtually parttition the vector to two parts.

129. sortedListToBST.cpp: sorted linked list to height balanced BSTree. We just find the middle pointer of the linked list and partition to two parts to build tree. Note about only 1 nodes case. As for how to find the middle pointer: I use cnt to capute the middle pointer. However, others use a better way (p skip twice every time and pMid skip once every time):<br>
  tail = NULL;//by default<br>
  p = head, pMid = head;<br>
	while (p != tail && p->next && p->next != tail) {<br>
			p = p->next->next;                   <br>                             
			pMid = pMid->next; <br>
	}<br>
  
130. isBalancedBTree.cpp: to judge if a bTree is a height balanced binary tree or not. write a function to return height with postorder traverse. And we determine if the abs(leftH - rightH)>1 at each node, if yes, then not balanced tree. 

131. minDepth.cpp: Note for the only-one-child case!!!!

132. hasPathSum.cpp: Note for the definition of the leaf node: both left and right child are NULL!!!

133. pathSum_store.cpp: Based on 132, we should store all the possible stores. dfs+backtracking.

134. generatePascalTriangle.cpp: generate pasical triangle.

135. getRow_vector.cpp: generate the kth's row pasical line.

136. minimumTotal.cpp: easiyl done with a two dimension dp. dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]), for i>=1, and 0<j<sz-1. Pay attention to the initialization.

137. minimumTotal_1dimDP.cpp, same as 136, but use one dim dp. maintain a prev vector and curr vector to measure the current smallest number.

138. maxProfit.cpp: Scan the array from left to right to find the maximum gap. Maintain a currMin during scan. Actually, this problem just allows only one transcation, if it allows numerous transcations, then this is a very hard problem.

139. flattenBTree.cpp: flatten a BTree to a linked list in a preorder sequence. Use preorder squence. Maintain a global prev pointer to indicate the current parent pointer. And let the current pointer to be right child of this global prev pointer. More importantly, we should also locally store the leftnode and right node of the current node every time so that we can preorder traverse it.

140. maxProfit_moreTranscation.cpp:  Same problem as 138, but it allows more than one trnscations totally. A greedy algorithm: for the current visited pointer, we find the first item of the first rigorously increased sequence, which is actually the minPrice from the current pointer on. Starting from this minPrice, we find the first item of the first rigorously decreased sequence, which is actually the maxPrice from the minPrice on. Thus, the biggest profit in this margin is maxVal - minVal. Then we move the pointer on to neighbor of the maxPrice pointer. And continue this process. Actually, we can easily prove that this method can give the max total profit.

141. maxProfit_twoTranscation_failure.cpp: I use the method as 140, and just store the biggest and 2nd biggest profit, and I return the sum of them, but failed. Check this one: [1,2,4,2,5,7,2,4,9,0].

142. maxProfit_twoTranscation.cpp: Use two for loops, the first for loop partition the array to two parts at each iteration, and we find 
the max profit (use methods in 138) in the left partition and right partition, and then we can finally get the max total profits. This requires O(n^2) time complexity but with O(1) constant space complexity. We can reform this method with the help of addtional O(n) space complexity to reduce the time complexity to O(n), as 143 mentioned.

143. maxProfit_twotranscation_faster.cpp: same as 143, but I change this method with the help of addtional O(n) space complexity to reduce the time complexity to O(n), as 143 mentioned. Use scan1 array to record the maximum profit so far to the current position which scans left to right. And use scan2 array to record the maximum profit so far to the current position which scans right to left. And then we check the maximum total value using scan1 and scan2.

144. maxPathSum.cpp: This is a very good problem. In the array, if we want to get the biggest sum of a certain consitutive part of arrays, we can easiy consider if the current sum value is greater than 0 or not, and then decide the dp[i] = data[i] or dp[i-1]+data[i]. In this problem, it changed to a tree, and we need to find the greatest sum of certain path from some starting node to some end node. Actually, we should use dfs with post-order traverse method: maintain a value (can be return value) recording the single path sum (may not contain the whole path but part of the path), and also maintain a variable recording the cross-path greatest path (can use reference parameter). If the single path sum<0, then the updated single path sum = 0+currnode->val, followed by it, we update the cross-path greatest sum accordingly.

146. isPalindrome.cpp: first preprocess the string, and then use while loop to scan from left to right and right to left at the same time.

147. numDistinct_dfs.cpp: Given a string S and a string T, count the number of distinct subsequences of S which equals T. I design a dfs method to search it. Though corrected, but TLE.

148. numDistinct.cpp: problem same as 147. But I use a two-dim dp method.  a). any s can have eact one match of "" (the end of s have a ""); b) use or not use the current match. dp[i][j+1] means we donot use s[i] to match t[j], then the result should be s[i-1] match t[j], dp[i][j] means we use s[i] to match t[j], the result should be same with s[i-1] match t[j-1]; c)we can only use the previous match, since we cannot use the current match, since we cannot use s[i] to match t[j], then we should use s[i-1] to match t[j], so it is dp[i][j+1].

149. connectTree.cpp: Populating Next Right Pointers (a perfect BTree) in Each Node. I use q queue to do bfs. However, if we need constant extra space, then we need some other methods.

150. connectTree_constantspace.cpp: same with 149. This time, we take advantage of the obserations: ob1. root->left->next = root->right; ob2. root->right->ext = root->next->left;

151. connectNonPerfectBTree.cpp: Populating Next Right Pointers (may not a perfect BTree) in Each Node. I use q queue to do bfs. However, if we need constant extra space, then we need some other methods.

152. connectNonPerfectTree.cpp: same as 151. This one use the constant extra space.   Explicit observation: ob1. if (root->right) root->left->next = root->right, else root->left->next = root->next->left (or right), we can use while to check the first found one; ob2. root->right->next = root->next->left (or right), we can use while to check the first found one.
Implicit solution: we use head to remember the leftmost pointer of a new layer, and use a tmp to link the nodes in a layer one by one. This is a very tricky method which does things implicitly. The very important point is here: we implicitly point the head to the first pointer of the next layer, since tmp directly link with head, so the first touch of tmp in a new layer, then it is assigned to head implictly. tmp is used to connect pointers in a layer implictly.

153. ladderLength.cpp: bfs solution. I write a standard bfs solution with only one while loop. To remeber the level information, I have to add a new level queue besides the myq which maintains the basic node information to maintain the level information. Actually, I can avoid it by finishing scan the current's level nodes within the while loop with an extra for loop, as ladderLength_1queue.cpp mentioned.

# old
for fun, forever

codes for poj. all C++ codes.

1. bfs.cpp: my solution for poj 3984. BFS for shortest path, and recursively trace back the path. I remebered a lot for solving it: how to define mutli-dim vector, how to define queue, how to define struct array, how to define direction, how to write BFS, how to trace path. Note, BFS is not implemented recursively itself (in contrast, DFS is usually implemnted in a recursive way).

2. unionSet.cpp: my solution for poj 2524. Simple application of Union Set. I memorized that time we prepared for ACM/ICPC contest. I re-learned how to implement a Union Set: makeSet, findSet, unionSet. Two keypoints: update root node along the trace path when union for a coming pair by finding operation (压缩路径); combine two subsets according to the rank (按秩合并).

3. binSearch.cpp: I wrote sample codes for binary search. Remeber to finish while loop when finding the target.

4. dfs.cpp: A poj problem (3050). DFS is quite commonly used. Remember the trace back after dfs. Here we donot need to use used to remember the visiting status like BFS. 

5. treeBuild.cpp: A poj problem (1577). Build a tree and then preorder traverse it. Given some specific information about a tree, and then ask you to build the that tree, such as, given two of post-order/pre-order/mid-order traverse sequences, ask you to inference the rest one's sequence. In this problem, the tree is BST, so the problem is much easier. And here I use a integer to simulate real pointer, actually it will be very cool if I use real pointer.

6. treeBuildwithBFSoutput.cpp: A problem for 3367. Build a tree according to post-order traverse, and then output the tree from down-to-up, right-to-left. The 1st part is easy done with Stack, the 2nd part should be done with BFS visit, and the reverse the visited sequence. Note, we use the integer to simulate the real pointer, and push the node index to the stack/queue, this makes the problem much easier.

7. simplePrim.cpp: My solution for 2485. A simple application of Prim algorithm to solve minimum spanning tree. The keypont to implement this algorithm is to maintain a vector to record the smallest distance between chosen sets and rest sets.

8. simpleKruskal.cpp: My solution for poj 1789. A simple application for Kruskal algorithm to solve minimum spanning tree problem. The keypoint is to store the graph in the form of edges. As we have to choose the smallest edges, thus we have to sort the edge array; and we also have to keep it a tree, so we have to exclude loop situation, so we can take advantage of unionSet learned before as a data structure to fulfill it. It's cool. One more important thing is that we have to use scanf instead of cin, because cin for string costs too much time, it will TLE.

9. sortIndex.cpp: My solution for 3663. A simple application of sort. And then I use two indexs to identify the left and right Index, and fix left index, count how many can be used from the right side (r-l); increase the left index, count from the right (from the last right index instead of the whole right index)...

10. nSmallestSum.cpp: My solution for 2442. Very beatiful codes!!! I like it. Not only logical analysis, but priority queue.
* This problem seems very complicated, actually, after simple analysis, it is easy:
* choose one value from each sequence, and get the sum, then we can have n^m sums. 
* if we only have one sequence, then we sort the sequence, it is the result.
* if we have two sequences, we have n^2 combinations, and we can get the top n minimum ones
* if we have three sequences, we just need to consider the top n minimum ones (generated by the first 2 sequences) and the coming 3rd sequence data
* if we have ....
* thus, every time, what we have to consider is just the coming n value and the resulting top n minimum ones
* we can use heap or priority queue to implement it
* Combining the above information, we have to maintain two data flow: the coming sequence, and the resulting sequenece from the last several sequences
* we can use two priority queue to represent the two, small Queue to store the generating results from the first k-1 sequence, and use array (num[]) to store the coming
* k-th sequenece. And we also use a temporary queue to store the temporary results which generates num[] and small queue.

11. stringProcess1.cpp: My solution for poj 2256. A simple string process problem. Remember to use getline(cin, string s) to enter one line of string,. cin or scanf will stop if they encounter a space or tab or \n. And also we have notice that "%.2f" which can keep 2 decimal.

12. LIS.cpp: My solution for poj 1631: the longest incremental subsequence (LIS) of a sequence. This is a classical dp problem. The code presented is O(nlogn). The logn comes from binary search funcion 'lower_bound'. Note, the key point is the definition of dp: the index is the length of current longest incremental subsequence, and the value of the element in dp is the smallest value which satisfies the LIS.

13. SubArrayMaxSum.cpp: we have to compute the maximum sum of a consecutive subarray. if maxendinghere is a sum which counts till the current element (array[currLoc]) and must contain the current element, otherwise, it cannot gurantee the consecutive. Thus, if the previous maxendinghere is positive, then we use it, if the previous maxendinghere is negtive, then we give up it.

14. lcs.cpp: given two strings x and y, we have to compute the longest common substring. a typical dp problem. 2-dim. consider whether the ending character equals or not.

15. given several types of coins (e.g., value 1,3 ,5), a target value n, we have to find the least coins we can have to get the n. sum[n]=min(sum[n-coin[0]],sum[n-coin[1]],sum[n-coin[2]]).
