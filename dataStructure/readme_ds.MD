1. LogSystem.cpp: a interesting problem. I choose to change the search item (start and end) following the granularity. And I use map to store the items and use lower_bound(>=) and upper_bound(>) to make a search.

2. MovingAverage.cpp: Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window. Solution: My first thought is to use a queue to store the elements, while it is hard to iterate the queue. So I switch to use list!!!! This is really an useful and powerful data structure. list has a lot of functions to use, like pop_front(), pop_back(), push_front(), push_back(). I indeed should learn it as early as possible, in that way, my fb will not fail... 
list: https://www.geeksforgeeks.org/list-cpp-stl/

3. MyHashMap_naive.cpp: problem: implement a hash map. I open a huge array, and then just do the simple remove, put and get.

4. MyHashMap_solveCollision.cpp: implement a hash map. I open a smaller array, use hash[hashed_key]={original_key, value}. And we solve the
key collision with modular and linear functions.

5. findWords.cpp (p212): Problem: Given a 2D board and a list of words from the dictionary, find all words in the board. Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
Solution: Use trie to build the dictionary, and write a dfs to search all possible words with trie's prunning.
