# codeBook
for fun, forever

codes for poj. all C++ codes.

1. bfs.cpp: my solution for poj 3984. BFS for shortest path, and recursively trace back the path. I remebered a lot for solving it: how to define mutli-dim vector, how to define queue, how to define struct array, how to define direction, how to write BFS, how to trace path. Note, BFS is not implemented recursively itself (in contrast, DFS is usually implemnted in a recursive way).

2. unionSet.cpp: my solution for poj 2524. Simple application of Union Set. I memorized that time we prepared for ACM/ICPC contest. I re-learned how to implement a Union Set: makeSet, findSet, unionSet. Two keypoints: update root node along the trace path when union for a coming pair by finding operation (压缩路径); combine two subsets according to the rank (按秩合并).

3. binSearch.cpp: I wrote sample codes for binary search. Remeber to finish while loop when finding the target.

4. dfs.cpp: A poj problem (3050). DFS is quite commonly used. Remember the trace back after dfs. Here we donot need to use used to remember the visiting status like BFS. 

5. treeBuild.cpp: A poj problem (1577). Build a tree and then preorder traverse it. Given some specific information about a tree, and then ask you to build the that tree, such as, given two of post-order/pre-order/mid-order traverse sequences, ask you to inference the rest one's sequence. In this problem, the tree is BST, so the problem is much easier. And here I use a integer to simulate real pointer, actually it will be very cool if I use real pointer.

6. treeBuildwithBFSoutput.cpp: A problem for 3367. Build a tree according to post-order traverse, and then output the tree from down-to-up, right-to-left. The 1st part is easy done with Stack, the 2nd part should be done with BFS visit, and the reverse the visited sequence. Note, we use the integer to simulate the real pointer, and push the node index to the stack/queue, this makes the problem much easier. 
