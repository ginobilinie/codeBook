1. pruneTree.cpp: Problem: We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.
Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
My solution: simple post-order traverse.

2. bstFromPreorder.cpp:
Problem: Return the root node of a binary search tree that matches the given preorder traversal.
Solution: 在主函数里用for loop调用N次，每次插入一个当前元素，插入时调用一次dfs函数。在dfs函数里，如果大于root，向右，如果右边是空，构建节点，插入之，如果不是，递归调用dfs；如果小于，向左，如果左边空，构建节点，插入之，如果不是，递归调用dfs。
扩展，其实如果是一个有序列表或者数组，让你构建bfs，也可以用类似在主函数里调用N次dfs函数每次构建一个元素的方法处理。
