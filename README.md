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
