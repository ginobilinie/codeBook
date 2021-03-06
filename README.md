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

27. mergeKLists.cpp: use priority_queue to maintain a k-min heap (k is the number of lists), and we should learn how use priority_queue, like priority_queue<type, container, compare>. Also, we should be very careful about the pointer operation. It is the linked list, we we can easily move to next. Time complexity: nk*log(k), and space complexity: O(k)

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

154. subarraysDivByK_tle.cpp: Given an array A of integers, return the number of (<b>contiguous</b>, non-empty) subarrays that have a sum divisible by K. A naive solution with two for loops. However, it will be TLE.

155. subarraysDivByK_presum.cpp: same problem as 154. I learned a new technique called <b>presum</b>!!! When we scan the array from left to right, we record the sum from the first item to the current item, and we make sum mod K, suppose the remainder is r, and we record how much this remainder will appear during the scan. if sameMod[r]=2, which means sum1%K = sum2%K, so (sum1-sum2)%K ==0, so we should add 1, when a new sum which has a mod remainder r come, we should add sameMod[r] to the final result, and then sameMod[r]++. This is a very technique solution, I learned a lot from this problem.
        <b>sameMod vector records the number of the prefix sums with same remainder against modouls K.
        Briefly speaking, we use sameMode to record the number of r = (A[0]+A[1]+...A[i])%K, and we use sameMod[r] counts it
        that's because if, two sameMod[r], then (sameMod1-sameMod2)%K==0, so we can add 1, 
        if a remainder r comes (assume we have previously x such remainder r), then we can use this new r to match the previous
        x remainders r, so we should add x to the final solution.</b>
	
156. findLadders_trace.cpp: same as 153, but we have to output the trace. The idea is use a queue of vector, the vector contains the candidate vectors which describes the path, if the candidate vector's end one matches the endWord, then we push back the candidate vector. The important point is how to use the used vector. When we scan each level (e.g., ith level), the used should be based on the i-th level, which means, for the ith level, the used should be same, so we used a tmpused = used when we can the ith level and update the ith level's information in used array.

157. longestConsecutive_unorderedArray.cpp: Given an unsorted array of integers, find the length of the longest consecutive elements sequence. Solution: use a map (red-black tree) to maintain the existence of the numbers. Since map's keys are ordered, so we can take advantage of its keys, and check the longest consecutive sequence. The drawback of this solution is that the insertion of N numbers of a  map may cost NlogN, since it has to adjust the order. If with a unordered map, what should I do?

158. longestConsecutive_unordered_map.cpp: Same problem as 157. I first use unordered_map to store these numbers (it is implemented by hash-table, so it is O(N)), and then we pick the first element, and while loop in the upper side and while loop in the lower side, each time, when we pick a value from the unordered_map, we should erase(key) this elements, after this while loop, then we pick a new first element of the map, and do it again.

159. sumNumbers_allPath.cpp: pre-order traverse. Note the definition of the leaf nodes.

160. flip_board.cpp: simple but boring dfs.

161. The longest Palindromic Substring problem. I have write a scan string version which is faster. In this version, we can write it a dp problem. And the dynamic status convert equation: consider a substring with len-length
        dp[i][j] = {1;//i==j dp[i+1][j-1];//s[i]==s[j] 0//s[i]!=s[j]}
        initialization: dp[i][i] and dp[i][i+1]
        and we can consider from len=3 to len to s.length()
	
162. partitionPalindrome.cpp. DP + DFS. We first use the method mentioned in 161 to build a dp table which obtain information about whether s[i..j] is a palindrome or not. Then we can take advantage of this dp table to dfs to obtain all the possible combinations. This is a quite good problem. My solutions acutally is very fast (8ms).

163. minCutPalindromePartitioning.cpp: This is following 161,162, and it wants you to give the min number of partitions that can cover the whole string. My solution: dp+bfs. DP is as 161 and 162, to maintain a dp table about whether s[i...j] is palindrome or not. With this dp table, then we can easily use bfs to search the shortest path to cover the whole string. Pay attention to the prunning. Actually, our solution is a very fast solution (16ms).

164. cloneGraph.cpp: deep copy of a graph which may contain self-cycle or repeated connection (like, 3->4, 3->4). This is not hard, but I can learn a lot from it. We need a unordered_map to maintain information about whether each node has been visited or not. dfs+graph+deepcody. Concept of deep copy: open new memory to store the object or values. When there are pointers, we neede deep copy, otherwise two calls of deconstructor will be a problem.  

165. cloneGraph_bfs.cpp: same problem as 164. This time, I use bfs to do the deep copy of a graph. The important point is that a visited node doesn't need to visit again, which means we donot need to add it to queues once a node has been visited.

166. canCompleteCircuit.cpp: Simple O(n^2) method with pruning and mod for the circuit algorithm. 104ms. I'll write a O(n) algorithm with presum technique.

167. canCompleteCircuit.cpp: first compute the elementwise different between gas and cost. Then we compute the cumulative sum, and check the minimum value's index. If the final element's cumulatvie result is >=0, which means there much be a route, and it should be the next index of minimal value's index. This is actually very tricky solution.

168. candy.cpp: In my first thought, I think we can first find the min value, and propogate from the min value location to the left or right sides. Obviously, this cannot work for long sequence. Then I though we can sort this ratings together with their location information. Then we sort from left to right we can use map (automatically ranking the key) or use a struct to sort the ratings with its location. Then we can the sorted array from left to right and check if the index's left or right is visted or not, if neighbors are not visited, then we assign 1, otherwise max(leftVal, rightVal) or max(leftVal, rightVal)+1. Actually, a better solution is to find the partitions of longest decreasing sequences. For example, [5,4,3,3,2,1,1,7,6], [5,4,3|,3,2,1|,1,|7,6], then the candy should be [3,2,1,3,2,1,1,2,1], so totally sum(candyarray).

169. singleNumber.cpp: Given a non-empty array of integers, every element appears twice except for one. Find that single one. Use xor (in c++, it is ^). Note, same number xor same number = 0, but 0 xor x = x. 4^6 = 100^110 = 0 1 0 

170. copyRandomList.cpp: deep copy a linked list with additional random pointer. Two parallel while loop. The first while loop build the linkedlist by tail insert, and second linked list for random pointers. Remeber to use the unordered_map.

171. wordBreak_tle.cpp: given a string and a dict, to check if the string combined with one of multiple words to combine the string. In this version, I give a recursion method, but TLE. With simple revision, I just used a visited array to check if the current location is visited or not, then I can do most of the pruning. Codes are in wordBreak.cpp.

172. wordBreak_path.cpp: same as 171, but it asks us to output all the possible results. The current version is actually correct, but may TLE in some cases.

173. hasCycle.cpp: using unordered_map to record the node is visited or not. I also write a double-single skip method which doesn't need extra space in hasCycle_doubleSkip.cpp.

174. detectCycle.cpp: to find the first cycle point. I use a unordered_map to do it. Now I write another one without extra space. 
The idea is first to use double skip skill to locate the first encountered point. And then we can start from the head and start from the encountered point, go with single skip, the first encounter point is the result we like to see.

175. reorderList.cpp: Given a singly linked list L: L0→L1→…→Ln-1→Ln, reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→… My solution: first find the mid pointer using double skip and single skip technique; and then reverse the 2nd linked list: Ln->Ln-1->Ln-2->...; and then we combine the first part and second part by iteratively link.

176. preorderTraversal.cpp: simple recursive function.

177. preorderTraversal_whileloop.cpp: We use a while loop and stack to do the preorder traverse. After we visit the current node, we store the right child (non-empty) to the stack, and go the left node. If left node is not null, then we get the top node of the stack, and go on the while loop. 

178. postorderTraversal.cpp: this is a simple recursive version for postorder traverse.

179. postorderTraversal_while_stack.cpp: We use a while loop and stack to do the non-recursive version. I also use a unordered_map to record whether it has been recorded or not.
we use stack to help following the rule: 
         when we go to the current node
        1. we first check if it is leaf node, if it is, we visit it and record this visit
        2. if it is not a leaf node, then we check if the left child has been visited or not, if not, store the current node, and go to the left; if visited, go to the right if right hasn't been visited, if right has been visited or null, then we directly visit the curre node, and pop the stack, and then get the top to the new pointer.
        3. if it doesn't have a left child, then we check the right child. if right one is visited, then we directly visit the current node, and pop, and then get the top as the new pointer. if right hasn't been visited, we store the current node to the stack and go to the right.

180. postorderTraversal_2stack.cpp: same problem as 178 and 179. I also write another non-recursive version using two stacks
        The first stack stores the current node's left and right child nodes, and pop the top one to the sencond stack,
        which means the 2nd stack acutally stores the reverse order of the post-oreder traverse

181. insertionSortList.cpp: simple linked list process. Pay attention to the head cases. Insertion sort: every time we choose one value (from left to right), and insert it to the proper location in the already-sorted-list. 

182. sortList_mergeSort.cpp: sort the linked list with mergeSort algorithm, sort and merge.

183. evalRPN.cpp: use stack to simulate the post-order traverse.

184. LRUCache.cpp: Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.  My solution: I'd like to take advantage of the unordered_map<int, int>, I thought unordered_map will keep the original insertion order, and it did keep the insertion order in my visual studio 2010, however, it doesnot keep the order in the OJ platform. I have covered the knowledge for unordered_map and unordered_set, and I got it: if the insertions doesnot break initial size of the unordered_map (unordered_set), then the unodered_map or unordered_set need to rehash, so the insertion order may be broken. 

185. reverseWords.cpp: use stack to help reverse and pay attention to the spaces (use word to preprocess it).

186. maxProduct.cpp: Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product. Solution: every time, we maintain the currMax, currMin and hisMax. currMax = max(max(currMax*nums[i],currMin*nums[i]),nums[i]); currMin = min(min(prevMax*nums[i],currMin*nums[i]),nums[i]);

187. findMinInSortedArray.cpp: this one is without duplicate values. bisearch, firt judge if a[left]<a[right], if yes, break; then judge if left or right side is ordered.

188. findMinInSortedArray.cpp: this one is with duplicate values. bisearch, at each while iteration, we first remove the duplicate values with a while(l<r&&a[l]==a[r])r--, then just follow the 187 but also consider the == cases sepearately.

189. MinStack.cpp: simuate a minimal stack which has an extra function called getMin(). At first, I write a simple implementation with only vector, it cost about 92ms. Then I write another implementation in MinStack_faster.cpp with vector and map, it costs about 28ms. However, map's insertion is log2N, so we should develop a new datastructure. Since we just need to store the current min togethe with the current push value. I use pair to implement a vector<pair> data structure in MinStack_pair.cpp.
	
190. getIntersectionNode.cpp: Write a program to find the node at which the intersection of two singly linked lists begins. while+unordered_map. O(n) time complexity with O(n) extra space complexity. We can also use set to replace unordered_map.

191. getIntersectionNode_noextraspace.cpp: same as 190, but we donot use extra space here. Here we provide a little bit of logic  based method: 
<pre>Suppose there are two list, listA and listB, the length of these two list is lenA, lenB, and pA and pB point to the head of these two lists respectively.
Round 1: Assume lenA > lenB, so for the first round pB will point to null first and we have length:
Round1: lenA - lenB; 0
Round2: After we point pB to listA, we get:
Round2: lenA - lenB, lenA
Round3: And then in this round, pA will point to null first, and we get:
Round3: lenB, lenB
Now we know that this round will be the final round since then length of pA and pB is the same and we only need to wait for them to point to the same node if the intersection point exists.
</pre>

192. findPeakElement.cpp: stupid, just need a for loop pass.

193. maximumGap_sort.cpp: directly sort and then a for loop pass. If we need to solve it in O(n), then we should not sort it.

194. radixSort.cpp: 1) Do following for each digit i where i varies from least significant digit to the most significant digit.
………….a) Sort input array using counting sort (or any stable sort) according to the i’th digit. The time complexity of radix sort is (d*(n)), where d is number of digits for the maximum value.
Here we make it understandable via an example:
<pre>
Original, unsorted list (arr): 170, 45, 75, 90, 802, 24, 2, 66
Iteraition 1: consider the least significant digit (1st)
unordered_map<int,vector<int>>: 0: 170, 90; 2: 802, 2; 4: 24; 5: 45, 75; 6: 66
vector<int> arr: 170, 90, 802, 2, 24, 45, 75, 66
Iteration 2: consider the next digit (10st)
unordered_map<int,vector<int>>: 0:802, 2; 2: 24; 4: 45; 6: 66; 7: 170, 75; 9: 90
vector<int> arr: 802, 2, 24, 45, 66, 170, 75, 90
Iteration 3: consider the most significant digit (100st)
unordered_map<int,vector<int>>: 0: 2, 24, 45, 66, 75, 90; 1:170; 8: 802
vector<int> arr: 2, 24, 45, 66, 75, 90, 170, 802
</pre>

195. maximumGap_radixSort.cpp: same problem as 193, but we write radix sort instead.

196. twoSum.cpp: sorted array. while loop, l and r pointers.

197. convertToTitle.cpp: 26 decimal

198. majorityElement.cpp: Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times. Solution: I use a unordered_map to record it with a for loop pass (record maxVal and res during scaning).

199. majorityElement_constantSpace.cpp: same with 198. We donot use extra space to solve it, and this is a very tricky solution: make full use of the definition: "more than n/2 times". We use a variable "val", and "val" records the so-far most frequent value. Other elements counterweigh one time of the current most frequent value, if cnt still >0, then means it is still the most frequent value. cnt==0, means it is not the so-far most frequent value.

200. trailingZeroes.cpp: count the number of 5s among [0,n], in the 1st iteration, we count the 1st 5: n/5; in the 2nd iteration, we count the 2nd 5, n/5/5, and ...

201. BSTIterator.cpp: inorder traverse with recursive function and use vector to records the visited sequence.

202. BSTIterator_norecursion.cpp: inorder traverse with no recursive function (simulate with stack+set) and use vector to records the visited sequence.

203. BSTIterator_norecusive_faster.cpp:  inorder traverse with no recursive function (simulate with only stack) and use vector to records the visited sequence.

204. uniquePathsIII.cpp: go from start to end (obstacles cannot go), and all empty grids should be visited and only visited once.

205. distributeCoins.cpp: we clean the tree down side to up side, and left side to right side. Actually, it is a postorder traverse.
I also write a postorder traverse: distributeCoins_postorder.cpp with parent and child nodes as parameters.

206. flipMatchVoyage.cpp: preorder traverse.  Observation: 1. if root node is not same with the current node in voyage, then we cannot match the voyage via the swap; 2. if root->val is the same with current node in voyage, then we check if left node is same with current node's next one (currInd++), if not, let's swap. 

207. prisonAfterNDays.cpp: There are 8 prison cells in a row, and each cell is either occupied or vacant... Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.). This is a very interesting problem. We have to notice that there are only 6 cells can be changes, so totally 64 possible changes, so if N>64, there must be a circle, so we can do simulation in the first 64 iterations, and find the circleStart and circleEnd, and then we can know where is the circle length. With simple mod operation, we can easily get the answer.

208. isCompleteTree.cpp: In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h. Solution: we search the tree via bfs, and record the first in-complete node, after this first incomplete node, the rest nodes should not have childs, otherwise, it is not complete.

209. isAlienSorted.cpp: pay attention to correctly understand the problem. unordered_map to stor the sequence.

210. canReorderDoubled.cpp: We have to find whether all the elements can be paired or not. We apply a greedy thought to this problem by sorting the array (otherwise, they may not be able to find the most proper pair, since one element can be paired by \*2 and /2 if possible). And we also use a unordered_map to record the number of elements, if paired, map[key]-- and map[2\*key]-- (map[2/key]--). Pay attention to the map.count function, it will only return 0 or 1. 

211. minDeletionSizeII.cpp: Problem: We are given an array A of N lowercase letter strings, all of the same length. Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices. Solution: This is not a hard problem, but hard to get accepted because you have to very carefully consider the same char problems. I set up 3 states: 0: prev<curr, 1: prev==curr, 2: prev>curr, after scanning all the words for the current char, if state is 0, then we return the current res since it is ordered for the remaining sequences; if state is 2, we should do res++; if state is 1, which means there are some same chars in some words, in this case, we donot need to remove this char, and we also cannot think the words is well sorted because we have to still consider the same char words. I use a vector to record it, and then continue to consider the unordered words for next chars.

212. tallestBillboard_TLE.cpp: Given a set of numbers, partition them to 3 parts, the first and second part should have the equal sum, and we have to get the maximum equal sum, and the 3 subset can be null and also cannot not null. Brute force: each element can choose to add to s1, s2 or s3(not add), so we can do dfs: max(dfs(s1+curr[i],s2), dfs(s1, s2+curr[i]), dfs(s1,s2))...but it will TLE.

213. lengthOfLIS.cpp: state: dp[i] means the LIS for the current i. consider dp[i+1], then we should compare with all the dp[0], dp[1],...dp[i], and then we can decide dp[i+1].

214. KthLargest.cpp: Kth Largest Element in a Stream. Solution: use priority_queue to maintain a min-heap, every time, when the heap is full (at maxSz), then we just need to do pop. priority_queue<int, vector<int>, greater<int>> is min-heap, less<int> is max-heap.

215. findKthLargest.cpp: maintain a k-min-heap with priority_queue

216. Trie.cpp: Define a trieNode: bool isWord (or int count): is it a word from root to the current node, and a 26 (or more) TrieNode* childs[26]....

217. numUniqueEmails.cpp: for loop scan with unordered_set

218. findRepeatedDnaSequences.cpp: slide window scan with unordered_set, pay attention to corner case.

219. isLongPressedName.cpp: note for the corner cases.

220. minIncrementForUnique.cpp: a intereting problem, similar with balance coin tree problem. We can first use a map to count the numbers. Then we can move the the number to the right neighbor even if the right neighbor is full, and we can for loop to can the map.

221. validateStackSequences.cpp: Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack. Solution: in a while loop, push all the elements before the current popInd into stack, then we discuss if s.top equals to or not equals to the poped[popInd]. Note, if the s is empty and the vector is not finished, then we should continue to push sth into the stack.

222. TimeMap_tle.cpp: use unorded_map<key,piroirty_queue<pair<value,int>>> to model the data structure, since I donot know how to do bisearch for priority_queue, so I choose linear search, but it is tle when the sequence is quite long.

223. verticalTraversal.cpp: vertical traverse a tree. We use a tuple based set (we have to rewrtie the struct cmp {operator()(const &n1, const &n2) return n1.val<n2.val};) with dfs to store the locations of all elements (loc: x,y,val).

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
